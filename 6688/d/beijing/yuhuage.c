// Room: /u/p/pock/bj/yuhuage.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"雨花阁"NOR);
	set("long", @LONG
雨花阁其实是一个小亭，南边有一个小水池，水池中长了办池的浮荷。
一些叫不出名字的鱼儿在水里自由自在地游来游去。它们自由自在，至少
要比宫中很多人要自由得多。真是一个鲜明的对比。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"yihuadian",
		"west" : __DIR__"guodao4",
		]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
