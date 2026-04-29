// Room: /u/p/pock/bj/fang2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"尚膳房"NOR);
	set("long", @LONG
这里是尚膳监总管的住居。不过现任御尚监总管海大富在宫中可算是个名人
了，来往也有些门道，所以把这里作为接待客人用的一个私厅，他和另外一个小
太监住在里屋。由于海大富的威严，这里没有什么杂闲人随意走动。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"fang3",
		"east" : __DIR__"houyuan",
	]));

	setup();
	replace_program(ROOM);
}
