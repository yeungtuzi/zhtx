
inherit ROOM;

void create()
{
	set("short", "沙漠");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rsmtotlf0",
	"east" : "/d/road/shamo0",
]));

	setup();
	replace_program(ROOM);
}
