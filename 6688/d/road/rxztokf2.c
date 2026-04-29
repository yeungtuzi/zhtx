// Room: /d/road/rxztokf2.c

inherit ROOM;

void create()
{
	set("short", "[1;36m驿道[2;37;0m");
	set("long", @LONG
LONG
	);
	set("outdoors", "road");
	set("exits", ([ /* sizeof() == 2 */
		"northwest" : "/d/road/rxztokf3",
		"east" : "/d/road/rxztokf1",
]));

	setup();
	replace_program(ROOM);
}
