//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"恶龙洞"NOR);
	set("long", @LONG
	一进水洞，迎面一股阴风扑来，只见一条长过十丈，头大如斗的恶龙恶狠狠
地朝你扑了过来。
LONG
);
	set("exits", ([
		"up": __DIR__"xihu4",
	]) );
	set("objects",([
	__DIR__"npc/dragon" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "up" && (present("dragon", environment(me))))
        return notify_fail("你想逃，但恶龙用庞大的身躯堵住了去路。\n");
        return ::valid_leave(me, dir);
}
