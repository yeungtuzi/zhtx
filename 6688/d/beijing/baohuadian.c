// Room: /u/p/pock/bj/baohuadian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"保华殿"NOR);
	set("long", @LONG
这里是保华殿。在皇宫之中，这种侧殿很多，虽然装修的和其它宫殿一样的
华丽，但并没有怎么使用。而且这里靠近皇宫的西北角，地处偏僻，来往走动的
人少多了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"guodao4",
		"north" : __DIR__"fire",
]));

	setup();
	replace_program(ROOM);
}
