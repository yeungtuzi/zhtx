// Room: /open/hihi/jie21.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"福州大街"NOR);
	set("long", @LONG
  走在大街上，你被周围的货物搞得眼花缭乱了,真有乱花渐欲迷人眼
的感觉。街道的东边是一个花店，西边是远近闻名的福威镖局。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jie31",
  "north" : __DIR__"jie11",
  "east" : __DIR__"huadian1",
  "west" : __DIR__"menfang1",
]));

	setup();
	replace_program(ROOM);
}
