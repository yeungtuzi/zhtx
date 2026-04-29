// Room: /d/xixia/hubu.c

inherit ROOM;

void create()
{
	set("short", "户部");
	set("long", @LONG
这里是户部，掌管全国土地、户籍、赋税、财政收支等事务。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad5",
]));

	setup();
	replace_program(ROOM);
}
