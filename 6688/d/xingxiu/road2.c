// Room: /d/xingxiu/road2.c

inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
一条僻静的小道，两旁是杂草灌木。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road3",
  "west" : __DIR__"road1",
]));
	set("outdoors", "xingxiu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
