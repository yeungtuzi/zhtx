// /d/wizard/tiantan1.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "天堂");
	set("long", @LONG
这里是造物主的天堂，世界万物就是造物主在这里造出来的
LONG
	);

        set("objects", ([
                __DIR__"npc/creater":1 ]) );

	set("exits", ([
		"down": __DIR__"wizard_room",
		 ]));
	set("no_fight", "1");

	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_creat_npc_query", "npc_query");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "造物主抬头看了一眼，说道：这位" + RANK_D->query_respect(ob)
                                + "，最近有造了些什么垃圾？\n");
}

void do_creat_npc_query(string listfile)
{

	object ob;
	ob = load_object("/data/emote.o");
	if( !ob ) 

		CHANNEL_D->do_channel(this_player(),"sys", "fail");
	else { 
		CHANNEL_D->do_channel(this_player(),"sys","yes");
		CHANNEL_D->do_channel(this_player(),"sys",ob->query("emote")["kick"]["target"]);
		}
	CHANNEL_D->do_channel(this_player(),"sys","xixi");

}
