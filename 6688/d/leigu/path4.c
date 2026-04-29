// Room: /d/leigu/path4.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
你在松树林里穿梭着，这里的松树遮天蔽日，连阳光都很难透过一点来。
轻风袭过，松枝摇曳，你仿佛看见了千万伏兵，你不禁佩服起当年岳飞
的计策，只可惜。。。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"path5",
  "eastdown" : __DIR__"path3",
]));
	set("objects", ([
		__DIR__"npc/fan" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "leigu");

	setup();
	replace_program(ROOM);
}
