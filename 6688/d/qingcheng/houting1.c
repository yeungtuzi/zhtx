// Room: /open/hihi/houting1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"过道"NOR);
	set("long", @LONG
这是连接镖局大厅和林家后院的一条通道，过道不大，而且过道边上又摆
放着一些旧木材，使不大的通道显得更小了，仅能允许两个人肩并肩的通过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "west" :__DIR__"guodao",
	  "east" : __DIR__"bj",
		]));

	setup();
	replace_program(ROOM);
}
