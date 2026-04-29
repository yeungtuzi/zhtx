// Room: /open/hihi/shanmen1.c

inherit ROOM;

void create()
{
	set("short", "青城山门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanmen",
  "south" : __DIR__"jianchi",
]));

	setup();
	replace_program(ROOM);
}
