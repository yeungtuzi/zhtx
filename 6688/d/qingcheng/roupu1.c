// Room: /open/hihi/roupu1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"肉铺"NOR);
	set("long", @LONG
 这里是一个小肉铺，和外边大街相比， 冷清多了。只有一个屠夫在
忙着支解一只又大又肥的山猪。许许多多的苍蝇在山猪肉上飞来飞去太不
卫生了，还是快点走吧。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jie11",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tufu" : 1,
]));

	setup();
	replace_program(ROOM);
}
