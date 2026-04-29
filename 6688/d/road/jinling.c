
inherit ROOM;

void create()
{
	set("short", "金陵");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/jldukoun",
	"southeast" : "/d/road/rjltosz0",
]));

	setup();
	replace_program(ROOM);
}
