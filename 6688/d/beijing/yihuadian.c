// Room: /u/p/pock/bj/yihuadian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"英华殿"NOR);
	set("long", @LONG
这里是英华殿。在皇宫之中，这种侧殿很多，虽然装修的和其它宫殿一样的
华丽，但并没有怎么使用。而且这里靠近皇宫的西北角，地处偏僻，来往走动的
人少多了。更何况，在皇宫之中，房子千万，一般人是很难把各个地方都记住的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"yuhuage",
		"east" : __DIR__"shngong",
]));

	setup();
	replace_program(ROOM);
}
