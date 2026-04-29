// Room: /open/hihi/jie41.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"福州大街"NOR);
	set("long", @LONG
这里已经到了福州的南端了.和北面的大街相比,这里明显的冷清多了.两
边的建筑多是新建的,有的还没有建好.这一片城区应该是刚刚在起步之中.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"nankou1",
	  "north" : __DIR__"jie31",
          "east" : __DIR__"yamen",
	]));

	setup();
	replace_program(ROOM);
}
