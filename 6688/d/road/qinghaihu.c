
inherit ROOM;

void create()
{
	set("short", "青海湖");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/road/rqhhtolz0",
	"southwest" : "/d/road/rqhhtoxsh0",
	"west" : "/d/road/rqhhtokl0",
]));

	setup();
	replace_program(ROOM);
}
