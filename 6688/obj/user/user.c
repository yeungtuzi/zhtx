// user.c

#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;

nosave int last_age_set;

void create()
{
	::create();
	set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
	// Accumulate potential.
	if( (int)query("potential") - (int)query("learned_points") < 100 )
		add("potential", 1);
	// Decay thief flag.
	if( (int)query("thief") > 0 ) add("thief", -1 );

	// 寿命将尽
	if( query("age") > query("max_age")-2 && !random(20) )
	{
		tell_object(this_object(),"你突然觉得一阵头晕目眩，眼前似乎出现了玫瑰色的光环，笼罩着一切。\n");
		tell_object(this_object(),"好容易，你慢慢地总算又恢复清醒，看来该注重一下自己的健康状况了...\n\n");
	}	
	
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

// This function update player's couple faith, by time both online.
// Yeung
void update_couple_faith()
{
        object her;
        string cup;
	int eff;

        if( query("gender")=="男性" ) return;
        cup = query("husband/id");
        if( cup && objectp(her=find_player(cup)) )
        {
		eff = 60+random(40);
		if( present(her,environment(this_object())) )
		{
		 	eff *= 4/3;
			cup = query("room/id");
			if( file_name(environment(this_object())) == "/data/room/"+cup[0..0]+"/"+cup )
				eff *= 3/2;
		}

                add("couple_faith",eff);
                her->add("couple_faith",eff);
		tell_object(this_object(),"你和"+her->name()+"的夫妻感情加深了。\n");
		tell_object(her,"你和"+this_object()->name()+"的夫妻感情加深了。\n");
        }


}

// This function updates player's age, called by heart_beat()
void update_age()
{

	// Update the time we spend on mudding, using method from TMI-2 mudlib.
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();
}

private void user_dump(int type)
{
/*
	object link_ob;
	
	link_ob = query_temp("link_ob");
*/
	
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "断线超过 "
				+ NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
			save();
                        move("/obj/misc/void");
                        interrupt_me(this_object(),"death");
			command("quit");
			command("quit");
			return;
			break;
		case DUMP_IDLE:
			// wiz don't get kicked out (Elon 10-17-95)

			if (wizardp(this_object()) || raw_wiz_level(this_object()) ) return;
			tell_object( this_object(), "对不起，您已经发呆超过 " 
				+ IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
			tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
				+ "化为一堆飞灰，消失了。\n", ({this_object()}));
			save();
		        move("/obj/misc/void");
                        interrupt_me(this_object(),"death");
                        command("quit");	
			command("quit");
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
                this_object()->fire_trigger("OnDisconnect");
                if( !this_object() ) return;
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

