
inherit ROOM;

void create()
{
	set("short", "岳阳");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rwctoyy1.c",
	"south" : "/d/road/ryytocs0.c",
]));

	setup();
	replace_program(ROOM);
}
