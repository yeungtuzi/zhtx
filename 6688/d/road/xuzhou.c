
inherit ROOM;

void create()
{
	set("short", "徐州");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rjntoxz2",
	"west" : "/d/road/rxztokf0",
	"south" : "/d/road/rxztodk0",
]));

	setup();
	replace_program(ROOM);
}
