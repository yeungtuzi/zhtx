// Room: /d/lingjiu/eastroom.c

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是灵鹫宫的武器储藏室。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"floor",
]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"obj/b_sword" : 3,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
