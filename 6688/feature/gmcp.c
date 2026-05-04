// gmcp.c - GMCP feature module
//
// Uses mudos-ng driver efuns: send_gmcp(), has_gmcp()
// Driver applies: gmcp_enable(), gmcp()

#include <dbase.h>
#include <gmcp.h>

nosave int gmcp_last_hash = 0;
nosave int gmcp_debug = 0;
nosave int gui_pushed = 0;

void gmcp_update_status();

// Escape string for embedding in JSON (Client.GUI lua field).
private string json_escape(string s)
{
    s = replace_string(s, "\\", "\\\\");
    s = replace_string(s, "\"", "\\\"");
    s = replace_string(s, "\n", "\\n");
    s = replace_string(s, "\r", "\\r");
    s = replace_string(s, "\t", "\\t");
    return s;
}

// Called by driver when client negotiates GMCP successfully.
void gmcp_enable()
{
    gmcp_update_status();
}

// Called by driver when client sends GMCP data to server.
void gmcp(string message)
{
    int sp;
    string package, body, script;

    if (!message || message == "") return;

    sp = strsrch(message, " ");
    if (sp == -1) return;
    package = message[0..sp-1];
    body = message[sp+1..];

    if (package == "Core.Supports.Add"
        && strsrch(body, "Client.GUI") != -1) {
        script = read_file("/data/gmcp_vitals.lua");
        if (script)
            send_gmcp("Client.GUI {\"name\":\"zhtx-status\",\"lua\":\"" +
                      json_escape(script) + "\"}");
    }
}

// Build JSON string covering all hp-command data fields.
private string build_vitals_json()
{
    mapping my;
    int max_food, max_water, pot;

    my = query_entire_dbase();
    max_food = this_object()->max_food_capacity();
    max_water = this_object()->max_water_capacity();
    pot = to_int(my["potential"]) - to_int(my["learned_points"]);
    if (pot < 0) pot = 0;

    return sprintf(
        "{"
        "\"gin\":%d,\"eff_gin\":%d,\"max_gin\":%d,"
        "\"kee\":%d,\"eff_kee\":%d,\"max_kee\":%d,"
        "\"sen\":%d,\"eff_sen\":%d,\"max_sen\":%d,"
        "\"force\":%d,\"max_force\":%d,\"force_factor\":%d,"
        "\"mana\":%d,\"max_mana\":%d,\"mana_factor\":%d,"
        "\"atman\":%d,\"max_atman\":%d,\"atman_factor\":%d,"
        "\"food\":%d,\"max_food\":%d,"
        "\"water\":%d,\"max_water\":%d,"
        "\"combat_exp\":%d,\"potential\":%d,"
        "\"magic_exp\":%d,\"tactic_exp\":%d,"
        "\"is_fighting\":%d"
        "}",
        to_int(my["gin"]), to_int(my["eff_gin"]), to_int(my["max_gin"]),
        to_int(my["kee"]), to_int(my["eff_kee"]), to_int(my["max_kee"]),
        to_int(my["sen"]), to_int(my["eff_sen"]), to_int(my["max_sen"]),
        to_int(my["force"]), to_int(my["max_force"]), to_int(my["force_factor"]),
        to_int(my["mana"]), to_int(my["max_mana"]), to_int(my["mana_factor"]),
        to_int(my["atman"]), to_int(my["max_atman"]), to_int(my["atman_factor"]),
        to_int(my["food"]), max_food,
        to_int(my["water"]), max_water,
        to_int(my["combat_exp"]), pot,
        to_int(my["magic_exp"]), to_int(my["tactic_exp"]),
        this_object()->is_fighting() ? 1 : 0
    );
}

// DJB2 hash — cheap, low collision for short vitality JSON strings.
private int str_hash(string s)
{
    int h, i, len;
    len = strlen(s);
    for (i = 0, h = 5381; i < len; i++)
        h = (h << 5) + h + s[i];
    return h;
}

// Push vitals via GMCP if data changed since last send.
void gmcp_update_status()
{
    string json;
    int h;

    if (!has_gmcp(this_object())) return;

    // Push GUI script once per session.
    if (!gui_pushed) {
        gui_pushed = 1;
        json = read_file("/data/gmcp_vitals.lua");
        if (json)
            send_gmcp("Client.GUI {\"name\":\"zhtx-status\",\"lua\":\"" +
                      json_escape(json) + "\"}");
    }

    json = build_vitals_json();
    h = str_hash(json);
    if (h == gmcp_last_hash) return;

    gmcp_last_hash = h;
    send_gmcp("Char.Vitals " + json);

    if (gmcp_debug)
        tell_object(this_object(), "[GMCP→Char.Vitals] " + json + "\n");
}

// Toggle debug mode: echo GMCP messages to main channel as well.
void gmcp_debug_toggle()
{
    gmcp_debug = !gmcp_debug;
    if (gmcp_debug)
        tell_object(this_object(), "[GMCP] 调试开启 — GMCP 消息将同时输出到主频道。\n");
    else
        tell_object(this_object(), "[GMCP] 调试关闭。\n");
}
