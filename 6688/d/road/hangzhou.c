
inherit ROOM;

void create()
{
	set("short", "杭州");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rhztosz0",
	"southwest" : "/d/road/rhztoyt0",
]));

	setup();
	replace_program(ROOM);
}
