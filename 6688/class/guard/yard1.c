// This is a room made by roommaker.
//modified by tlang for /class/guard/npc/host.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "食堂");
	set("long", "你来到平时不开放的食堂，这儿放有一些元宵，还有烟花(yanhua)\n"
		"在墙上，可取(qu)来放(shoot)。\n");
	set("no_fight",1);
/*	set("objects",([
	"/class/guard/npc/host" : 1,
	]));
*/
	setup();
}

void init()
{
	add_action("do_qu","qu");
}

int do_qu(string arg)
{
	object ob,obj;

	ob=this_player();
	if(!arg || arg=="")
		return notify_fail("你要取什么？\n");
	obj=new("/class/guard/npc/obj/yanhua");
	obj->move(ob);
	tell_room(environment(ob),RANK_D->query_respect(ob)+"从墙上取出一个烟花。\n");
		return 1;
}
