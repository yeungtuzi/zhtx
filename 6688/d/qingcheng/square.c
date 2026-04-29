// Room: /open/p/pock/square.c

inherit ROOM;

void create()
{
	set("short", "[35m练武场[2;37;0m");
	set("long", @LONG
青城派顺山而建， 能有那么一个大平台作为弟子们的练武处所，的确不错，
练武场的中央摆放着一个兵器架，当然，架上主要的是剑。一些青城派的弟子正
在这里练剑呢。.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/dizi1" : 8,
		__DIR__"npc/renying" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
		"eastdown" : __DIR__"shijie",
		"west" : __DIR__"guan1",
		"north" : __DIR__"tearoom",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
