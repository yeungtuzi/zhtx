// Room: /d/xixia/bingbu.c

inherit ROOM;

void create()
{
	set("short", "兵部");
	set("long", @LONG
这里是兵部，掌管全国武官选用和兵籍、军械、军令之政。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad3",
]));

	set("objects", ([
		__DIR__"npc/chage": 1,
	]));

	setup();
	replace_program(ROOM);
}
