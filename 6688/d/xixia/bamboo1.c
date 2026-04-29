// Room: /d/xixia/bamboo1.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
好大一片竹林，郁郁葱葱，也不知自己置身何处。微风起处，
但闻阵阵哗啦啦声。若在此设伏，当真死无葬身之地。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bank2",
  "west" : __DIR__"ygate",
]));

	setup();
	replace_program(ROOM);
}
