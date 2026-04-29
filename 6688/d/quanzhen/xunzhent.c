// Room: /u/kiss/quanzhen/xunzhent.c
// Made by: kiss

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "寻真台");
	set("long", 
 " 这是一处大理石砌成的平台，平台正中放着几只蒲团，似是得道高人打坐领悟之所。\n"
"其名"RED"寻真"NOR",似含玄机。此处南面是延灵阁，北面是走廊。\n"
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoulang15.c",
  "south" : __DIR__"yanlingg.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
