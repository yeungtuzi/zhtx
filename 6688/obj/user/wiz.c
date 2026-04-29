// wiz user.c

#include <origin.h>
#include <user.h>

inherit F_AUTOLOAD;
inherit F_SAVE;


#define SAVE_INT 300

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;  
inherit F_TRIGGER;
inherit F_ATTRIBUTE;
inherit F_ATTACK;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FAMILY;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;
nosave int save_flag,save_tick;

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
	set_name("特权使用者物件", ({ "user object", "user", "object" }) );	
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
	seteuid(getuid(this_object()));
	if( clonep(this_object()) ) {
		set_heart_beat(1);
		tick = 5 + random(10);

                //added by yeung
                save_tick = SAVE_INT;
                save_flag = 0; //第1,2,3次保存原始文件,第4次保存备份                
		
	        enable_player();

		CHAR_D->setup_char( this_object() );
	} else        		
		call_out( "clean_up", 5 );

	restore_autoload();		
}

void heart_beat()
{
 	object ob,link_ob;

        save_tick--;
        if( save_tick <= 0 )
        {
                        save_flag++;
                        if( save_flag > 4 ) save_flag = 0;
                        if( save_flag != 4 )
                        {
                                tell_object(this_object(),"自动存盘...");
                                this_object()->save();
                                if( objectp(link_ob=(this_object())->query_temp("link_ob")) )
                                      link_ob->save_back();
                                tell_object(this_object(),"完毕.\n");
                        }
                        else
                        {
                                tell_object(this_object(),"自动备份数据...");
                                this_object()->save_back();
                                if( objectp(link_ob=(this_object())->query_temp("link_ob")) )
                                        link_ob->save_back();
                                tell_object(this_object(),"完毕.\n");
                        }
                        save_tick = SAVE_INT;
        }        
        if( is_fighting() ) remove_all_killer();
        if( is_busy() ) continue_action();
	if( !interactive(this_object()) ) return;
}

int visible(object ob)
{
	int lvl, invis;

	lvl = wiz_level(this_object());
	if( lvl < raw_wiz_level(this_object()) )
		lvl = raw_wiz_level(this_object());

	if( lvl > wiz_level(ob) && lvl > raw_wiz_level(ob) ) return 1;
	
	invis = ob->query("env/invisibility");		
	if( intp(invis) && (invis > lvl) ) return 0;

    	return 1;
}

//可以由别的物件来调用     yeung
int fcommand(string custom_cmd)
{
     if( geteuid(previous_object())!= ROOT_UID ) return 0;
     return command(custom_cmd);
}

//和fy的兼容
int ccommand(string custom_cmd)
{
     if( geteuid(previous_object())!= ROOT_UID ) return 0;
     return command(custom_cmd);
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
	return;
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

varargs save(int flag)
{
	int res;

	if(!flag) save_autoload();
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

varargs save_back(int flag) {

	string src,dst;
        string id;

        id = geteuid();
        if( !id ) id = getuid();
        if( !stringp(id) ) return 0;
        src = sprintf(DATA_DIR "user/%c/%s", id[0], id);
	dst = src + ".bak.o";
	src = src + ".o";
	cp ( src , dst ) ;
	return 1;
}

private void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "断线超过 "
				+ NET_DEAD_TIMEOUT/10 + " 分钟，自动退出这个世界。\n");
			save();
			command("quit");
			command("quit");
			command("quit");
			return;
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	// remove_all_enemy(); Bug here,can fight,exert tanzhi ( or cast ),then disconnect

	set_temp("netdead", 1);
	if( userp(this_object()) ) {
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
	    tell_room(environment(), query("name") + "断线了。\n", this_object());
		CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
	} else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "重新连线完毕。\n");
}

varargs int receive_wound(string type, int damage, object who)
{
	if( query("env/test_damage") )
		tell_object(this_object(),"damage_type: "+type+" ,damage: "+damage+" \n");
	return 0;
}	

varargs int receive_damage(string type, int damage, object who)
{
	if( query("env/test_damage") )
		tell_object(this_object(),"wound_type: "+type+" ,wound: "+damage+" \n");
	return 0;
}	                

varargs int accept_kill()
{
	remove_all_killer();
	return 1;
}	                           

void die()
{
	return;
}	       

void unconcious()
{
	return;
}	

nomask void enable_player1()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
	
	if( stringp(query("id")) ) set_living_name(query("id"));
	else set_living_name(query("name"));

	enable_commands();
	add_action("command_hook", "", 1);

	switch( raw_wizhood(this_object()) ) {
		case "(admin)":
			set_path(ADM_PATH);
			enable_wizard();
			break;
		case "(arch)":
			set_path(ARC_PATH);
			enable_wizard();
			break;
		case "(wizard)":
			set_path(WIZ_PATH);
			enable_wizard();
			break;
		case "(apprentice)":
			set_path(APR_PATH);
			enable_wizard();
			break;
		case "(immortal)":
			set_path(IMM_PATH);
			break;
		default:
			set_path(PLR_PATH);
	}                       
	set_temp("supervision",1);
}

void write_prompt()
{
	if( sizeof(msg_buffer) ) {
		receive(BOLD "[输入时暂存讯息]\n" NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
        if( query_temp("supervision") )
        	write(HIY"管理模式> "NOR);
        else
		write("> ");	
}

// Protect data against hackers.
nomask mixed set(string prop, mixed data)
{
	if( geteuid(previous_object())!= ROOT_UID && prop=="secure_password" ) return 0;
	return ::set(prop, data);
}
