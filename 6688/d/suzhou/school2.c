// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"精进楼"NOR);
	set("long", @LONG
		你快步来到二楼，眼前的情景让你大吃一惊。只见这地方足足
有外边的练武场大，不知道是怎么建成的，而且房中稀稀落落地有十来个镖局弟
子，有的在练功，有的在向屋子中央椅子上的一位白发老人请教。
LONG
	);
	set("objects",([
	__DIR__"npc/fighter5" : 2,
	__DIR__"npc/jinwu" : 1,
	]));
	set("exits",([
	"down" : __DIR__"school",
	"up" : __DIR__"school3",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query("biao_ju") && dir == "up")
        	return notify_fail(RED"一股神秘的力量让你为之止步。\n"NOR);
        	return ::valid_leave(me, dir);
}

