// Room: /d/lingjiu/floor2.c

inherit ROOM;

void create()
{
	set("short", "后厅空地");
	set("long", @LONG
这里是后院的一块空地，连接着东西小路。北边是花圆入口。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"garden",
  "east" : __DIR__"road3",
  "west" : __DIR__"road2",
]));

	set("outdoors", "lingjiu");
	setup();
	replace_program(ROOM);
}
