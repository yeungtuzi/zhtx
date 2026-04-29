
inherit ROOM;

void create()
{
	set("short", "贵阳");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rgytodk0",
	"northeast" : "/d/road/rgytocs0",
//	"southwest" : "/d/road/rgytodl0",
	"southeast" : "/d/green/path6",
]));

	setup();
	replace_program(ROOM);
}
