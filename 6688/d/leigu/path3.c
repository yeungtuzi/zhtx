// Room: /d/leigu/path3.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
好容易穿过了竹林，不料前面又是一大片松树林，小径继续蜿延而
上，不知何时方可到达山顶。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"path4",
  "southdown" : __DIR__"path2",
]));
	set("objects", ([
		__DIR__"npc/wu" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "leigu");

	setup();
	replace_program(ROOM);
}
