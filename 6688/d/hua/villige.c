// Room: /d/hua/villige.c

inherit ROOM;

void create()
{
	set("short", "村庄");
	set("long", @LONG
这里是一座小村庄, 男人们可以在这里修筑自己的小木屋。
如果你想有个家的话, 就去村北头村长家买户口吧。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"main_house",
  "east" : __DIR__"road",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
