#include <login.h>
#include <ansi.h>
inherit ROOM;

private mapping wiz_status;
private mapping swiz_status;

private string *wiz_levels = ({
        "(player)",
        "(immortal)",
        "(apprentice)",
        "(wizard)",
        "(arch)",
        "(admin)"
});

private mapping trusted_write = ([
        "/":            ({ "Root", "(admin)",ROOT_UID}),
]);

private mapping exclude_write = ([
        "adm":          ({ "(arch)" }),
        "daemon":       ({ "(arch)" }),
        "std":          ({ "(arch)" }),
        "cmd":          ({ "(arch)" }),
        "data":         ({ "(arch)" }),
        "log":          ({ "(admin)" }),
        "include":      ({ "(arch)" }),
]);

void create()
{
        string *wizlist, wiz_name, wiz_level;
        int i;

        set("short", CYN"小溪边"NOR);
                        set("long", @LONG
到这里路断了。面前是一条清澈的小溪，偶尔可以看见
有鱼游来游去。旁边还放着几根钓鱼杆，也不知是谁忘在这
儿的。也许你可以用它来钓鱼(fish)哦。
LONG
        );
        wizlist = explode(read_file(WIZLIST), "\n");
        wiz_status = allocate_mapping(sizeof(wizlist));
        for(i=0; i<sizeof(wizlist); i++) {
                if( wizlist[i][0]=='#'
                || sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
                wiz_status[wiz_name] = wiz_level;
        }
        wizlist = explode(read_file(SWIZLIST), "\n");
        swiz_status = allocate_mapping(sizeof(wizlist));
        for(i=0; i<sizeof(wizlist); i++) {
                if( wizlist[i][0]=='#'
                || sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
                swiz_status[wiz_name] = wiz_level;
        }

}

void init()
{
       add_action("do_promote", "promote");
}

string *query_wizlist() { return keys(wiz_status); }
string *query_raw_wizlist() { return keys(swiz_status); }

int set_status(mixed ob, string status)
{
        string uid, *wiz, wizlist;
        int i;

     //   if( geteuid(previous_object())!= ROOT_UID ) return 0;

        if( userp(ob) )                 uid = getuid(ob);
        else if(stringp(ob))    uid = ob;
        else return 0;

        if( status == "(player)" )
                map_delete(wiz_status, uid);
        else
                wiz_status[uid] = status;
        wiz = keys(wiz_status);
        for(wizlist = "", i=0; i<sizeof(wiz); i++)
                wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
        rm(WIZLIST);
        write_file(WIZLIST, wizlist);
//        log_file( "static/promotion", capitalize(uid)
//         + " become a " + status + " on " + ctime(time()) + "\n" );
        return 1;
}

/*int set_raw_status(mixed ob, string status)
{
        string uid, *wiz, wizlist;
        int i;

   //     if( geteuid(previous_object())!= ROOT_UID ) return 0;

        if( userp(ob) )                 uid = getuid(ob);
        else if(stringp(ob))    uid = ob;
        else return 0;

        if( status == "(player)" )
                map_delete(swiz_status, uid);
        else
                swiz_status[uid] = status;
        wiz = keys(swiz_status);
        for(wizlist = "", i=0; i<sizeof(wiz); i++)
                wizlist += wiz[i] + " " + swiz_status[wiz[i]] + "\n";
        rm(SWIZLIST);
        write_file(SWIZLIST, wizlist);
        log_file( "static/promotion", capitalize(uid)
         + " become a " + status + " on " + ctime(time()) + "\n" );
        return 1;
}*/


string *get_wizlist() { return keys(wiz_status); }
string *get_raw_wizlist() { return keys(swiz_status); }

/*int valid_seteuid( object ob, string uid )
{
        if( uid==0 ) return 1;
        if( uid==getuid(ob) ) return 1;
        if( getuid(ob)==ROOT_UID ) return 1;
        if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
        if( wiz_status[uid] != "(admin)"
        &&      wiz_status[getuid(ob)] == "(admin)" )
                return 1;
        return 0;
}*/

int do_promote(string arg)
{
        object ob;
        string new_status;
        if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
                return notify_fail("指令格式：promote <使用者> <等级>\n");
        if( !objectp(ob = present(arg, this_object()))
                || !userp(ob) )
            return notify_fail("你只能改变使用者的权限。\n");
    if( !(set_status(ob, new_status)) )
                        return notify_fail("修改失败。\n");
    message_vision("$N将$n的权限改为 " + new_status + " 。\n", this_player(), ob);
    seteuid(getuid());
                ob->enable_me();

        return 1;
}

