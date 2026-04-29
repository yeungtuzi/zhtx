// Room: /u/hacky/quanzhen/chongxt.c
// Made by: hacky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "玄虚堂");
	set("long", @LONG
这是一间宽敞的屋子,整个房间由几根雕龙画凤的柱子撑着,房间的南面左右各立着一个和尚,他们手中持着木棍,
外面的人只能从他们面前经过.和尚头顶的屋檐下挂着一块木匾.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tianzd.c",
  "south" : __DIR__"xuanzt.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ma.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
