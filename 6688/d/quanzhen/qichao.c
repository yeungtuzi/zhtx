// Room: /u/kiss/quanzhen/qichao.c
// Made by: kiss

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"奇草"NOR);
	set("long", @LONG
奇草里有种满了各种各样的珍奇植物，这些都是全真七子云游四方时
带回来的，现在都种在这里，一位道长正在这里细心的照料这些奇草。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guoyuan.c",
  "east" : __DIR__"fanghua.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
