// Room: /u/p/pock/bj/beihai1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"北海"NOR);
	set("long", @LONG
这里是靠近皇宫的神武门侧，向东看去，遥遥可以见到神武门的高大围墙
和那雄伟的箭楼。往西，则是一些平民的居所，还有一些手工作坊，在皇宫的
周围形成了一个还算繁华的小商业带。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"shenwumen",
		"west" : __DIR__"xisi2",
		]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
