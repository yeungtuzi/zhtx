// Room: /d/leigu/didao1.c

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
一条阴冷潮湿的地道，伸手不见五指，你只能摸索着前进。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"didao2",
  "up" : __DIR__"floor",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
