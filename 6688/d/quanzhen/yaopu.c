// Room: /u/hacky/quanzhen/yaopu.c
// Made by: hacky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "药圃");
	set("long", @LONG
药圃内种着许多罕见的奇药,一位老者正在这里精心照看这些草药.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"mingmu.c",
  "south" : __DIR__"zoulang18.c",
  "east" : __DIR__"guoyuan.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laozhe.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
