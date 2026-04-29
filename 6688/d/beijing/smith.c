// Room: smith.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"打铁铺子"NOR);
	set("long", @LONG
这里是一间打铁铺子，从火炉中冒出的火光将墙壁映得通红，屋子的角
落里堆满了各式铁器的完成品或未完成品，近来行走江湖的人多了起来，所
以原来专打农具的铺子，现在都改打兵器了。说不定你能在这里挑到一件称
心的兵刃呢！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"changjie3",
//	  "south" :__DIR__"smith2.c",
		]));

	set("objects", ([
		__DIR__"npc/smith": 1,
		 ]) );
	setup();
	replace_program(ROOM);
}
