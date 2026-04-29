// securityd.c

#include <login.h>

// By Annihilator@Eastern.Stories (11/25/94)

// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
// 
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.

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

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.

private mapping trusted_write = ([
        "/":            ({ "Root", "(admin)",ROOT_UID}),
        "u":            ({ "(admin)","(arch)","(wizard)" }),
]);

private mapping exclude_write = ([
        "adm":          ({ "(admin)" }),
        "daemon":       ({ "(admin)" }),
        "std":          ({ "(admin)" }),
        "cmd":          ({ "(admin)" }),
        "data":         ({ "(admin)" }),
        "log":          ({ "(admin)" }),
        "include":      ({ "(admin)" }),
        "class":        ({ "(admin)" }),
        "feature":      ({ "(admin)" }),
        "quest":        ({ "(admin)" }),
        "ldg":          ({ "(admin)" }),
        "obj":          ({ "(admin)" }),
        "doc":          ({ "(admin)" }),
]);

void create()
{
        string *wizlist, wiz_name, wiz_level;
        int i;

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

string *query_wizlist() { return keys(wiz_status); }
string *query_raw_wizlist() { return keys(swiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
        string euid;
        
        if( objectp(ob) ) {
                if( clonep(ob) && !userp(ob) ) return "(player)";
                euid = geteuid(ob);
                if( !euid ) euid = getuid(ob);
        }
        else if( stringp(ob) ) euid = ob;

        if( member_array(euid, wiz_levels)!=-1 ) return euid;

        if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
        else return "(player)";
}

string get_raw_status(mixed ob)
{
        string euid;
        
        if( objectp(ob) ) {
                if( clonep(ob) && !userp(ob) ) return "(player)";
                euid = geteuid(ob);
                if( !euid ) euid = getuid(ob);
        }
        else if( stringp(ob) ) euid = ob;

        if( member_array(euid, wiz_levels)!=-1 ) return euid;

        if( !undefinedp(swiz_status[euid]) ) return swiz_status[euid];
        else return "(player)";
}


int get_wiz_level(object ob)
{
        return member_array(get_status(ob), wiz_levels);
}

int get_raw_wiz_level(object ob)
{
        return member_array(get_raw_status(ob), wiz_levels);
}


int set_status(mixed ob, string status)
{
        string uid, *wiz, wizlist;
        int i;

        if( geteuid(previous_object())!= ROOT_UID ) return 0;

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
        log_file( "static/promotion", capitalize(uid)
         + " become a " + status + " on " + ctime(time()) + "\n" );
        return 1;
}

int set_raw_status(mixed ob, string status)
{
        string uid, *wiz, wizlist;
        int i;

        if( geteuid(previous_object())!= ROOT_UID ) return 0;

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
}


string *get_wizlist() { return keys(wiz_status); }
string *get_raw_wizlist() { return keys(swiz_status); }

// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object.                                                                                           - Annihilator

int valid_write(string file, mixed user, string func)
{
        string euid, status, *path, dir;
        int i;

        if( !objectp(user) ) {
                return 0;
        }

        if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

        // Let user save their save file
//      printf("%s - %s - %s \n", user->query("id"),file,func);
        if( func=="save_object" ) {
                if( ( sscanf(base_name(user), "/obj/%*s") ||
                      sscanf(base_name(user),"/d/taishan/npc/%*s") ||
                      sscanf(base_name(user),"/data/room/%*s") 
                      )
                &&      sscanf(file, "/data/%*s")
/* for v22rpe 11 */
                && ( ( file ==  ( (string)user->query_save_file()+ 
                                   __SAVE_EXTENSION__ ) )  
                   ) 
                        
/* for v21.7 
                &&      file ==   (string)user->query_save_file()  
*/
                 )
                        return 1;
        }
/* for data backup dao 980219 */        
        if  ( file == ( (string)user->query_save_file()+".bak"+
                __SAVE_EXTENSION__ ) ) 
                 return 1;

        // Get the euid and status of the user.

        euid = geteuid(user);
        if( !euid ) return 0;
        status = get_status(user);
        // Check if we are hidden wizards
        // by YEUNG 2000-6-11
        if( status == "(player)" )
                status = get_raw_status(user);

        if( euid==ROOT_UID ) return 1;
	if( euid=="masterall" ) return 1;
//      if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") )
//              return 1;

        path = explode(file, "/");

        // Check if we are excluded in one of the directories containing the file.
        for(i=sizeof(path)-1; i>=0; i--) {
                dir = implode(path[0..i], "/");
                if( undefinedp(exclude_write[dir]) ) continue;
                if( member_array(euid, exclude_write[dir])!=-1 )
                        return valid_write(file, this_player(1), func);
                if( member_array(status, exclude_write[dir])!=-1 )
                        return valid_write(file, this_player(1), func);
        }

        // And then check if we are trusted in one of the directories containing
        // the file.
        if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
        if( member_array(status, trusted_write["/"])!=-1 ) return 1;
        for(i=sizeof(path)-1; i>=0; i--) {
                dir = implode(path[0..i], "/");
                if( undefinedp(trusted_write[dir]) ) continue;
                if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
                if( member_array(status, trusted_write[dir])!=-1 ) return 1;
        }

        return valid_write(file, this_player(1), func);
}

int valid_seteuid( object ob, string uid )
{
        if( uid==0 ) return 1;
        if( uid==getuid(ob) ) return 1;
        if( getuid(ob)==ROOT_UID ) return 1;
        if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
        if( wiz_status[uid] != "(admin)"
        &&      wiz_status[getuid(ob)] == "(admin)" )
                return 1;
        return 0;
}

