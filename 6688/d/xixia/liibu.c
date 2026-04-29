// Room: /d/xixia/liibu.c

inherit ROOM;

void create()
{
	set("short", "吏部");
	set("long", @LONG
这里是吏部，掌管全国官吏的任免、考课、升降、调动等事务。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad6",
]));

	setup();
	replace_program(ROOM);
}
