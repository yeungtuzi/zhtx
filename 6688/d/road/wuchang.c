
inherit ROOM;

void create()
{
	set("short", "武昌");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/hkdukoun.c",
	"south" : "/d/road/rwctoyy0.c",
]));

	setup();
	replace_program(ROOM);
}
