#include <login.h>

#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

void logon()
{
	set_temp("login_time", time());

	call_out( "time_out", LOGIN_TIMEOUT );
	LOGIN_D->logon( this_object() );
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
	remove_call_out("time_out");
	call_out( "time_out", 1 );
}

void time_out()
{
	if( objectp(query_temp("body_ob")) ) return;
	if( query_temp("create_new_char") ) return;
	if( interactive(this_object()) )
		write("您花在连线进入手续的时间太久了，下次想好再来吧。\n");
	destruct(this_object());
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}
int save_back() {

        string src,dst;
        string id;

	id = query("id", 1);
        if( !stringp(id) ) return 0;
        src = sprintf(DATA_DIR "login/%c/%s", id[0], id);
        dst = src + ".bak.o";
        src = src + ".o";
        cp ( src , dst ) ;
        return 1;
}


void receive_message(string type, string str)
{
	if( type!= "write" ) return;
	receive(str);
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);

	// Auto-detect encoding for old MUD clients
	if (term_type) {
		switch (lower_case(term_type)) {
		case "zmud":
		case "cmud":
			set_encoding("GBK");
			break;
		}
	}
}

// Escape string for embedding in JSON (Client.GUI lua field).
private string json_escape(string s)
{
    s = replace_string(s, "\\", "\\\\");
    s = replace_string(s, "\"", "\\\"");
    s = replace_string(s, "\n", "\\n");
    s = replace_string(s, "\r", "\\r");
    return s;
}

// Handle incoming GMCP messages.
// Mudlet sends Core.Supports.Add early in the handshake — if it
// announces Client.GUI support, push the vitals display script so
// the client auto-installs it.
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
        if (script) {
            send_gmcp("Client.GUI {\"name\":\"zhtx-status\",\"lua\":\"" +
                      json_escape(script) + "\"}");
            tell_object(this_object(), "[GMCP] Client.GUI script pushed.\n");
        } else {
            tell_object(this_object(), "[GMCP] read_file failed.\n");
        }
    }
}

// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data)
{
	if( geteuid(previous_object())!= ROOT_UID && (wiz_level(this_object()) || raw_wiz_level(this_object()) )) return 0;
	return ::set(prop, data);
}
