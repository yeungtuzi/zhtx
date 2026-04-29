// Room: /d/xixia/xingbu.c

inherit ROOM;

void create()
{
	set("short", "刑部");
	set("long", @LONG
这里是刑部，掌管全国法律、刑狱事务。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad2",
]));

	setup();
	replace_program(ROOM);
}
