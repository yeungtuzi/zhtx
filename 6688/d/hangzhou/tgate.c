// This is a room made by roommaker.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"凤林寺大门"NOR);
	set("long", "这是一座极小的寺庙，门紧闭着。后面围墙有处塌了，\n"
"也许能爬(climbup)进去。越过围墙往里面看，让人感到一种莫名其妙的恐惧。\n");
	set("exits", ([
	"west" : __DIR__"xhroad2",
	]));

	setup();
}

void init()
{
	add_action("do_climbup", "climbup");
}

int do_climbup()
{
	object me;
	me=this_player();

	if(!me->query("mark/goon"))
		return notify_fail("你攀住墙往上爬，眼看就要进去了，突然\n"
"有人从里面一脚把你踢了出来。\n");
	tell_object(me,"你悄悄地沿墙角爬了进去。\n");
	me->move("/d/hangzhou/temple");
		return 1;
}