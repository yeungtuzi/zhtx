
inherit ROOM;

void create()
{
	set("short", "长沙");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/ryytocs2.c",
	"south" : "/d/road/rcstogz0.c",
	"east" : "/d/road/rcstoyt0.c",
	"west" : "/d/road/rgytocs4.c",
]));

	setup();
	replace_program(ROOM);
}
