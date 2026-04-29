
inherit ROOM;

void create()
{
	set("short", "开封渡口");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rdktojd0",
	"south" : "/d/road/kfdukou0",
]));

	setup();
	replace_program(ROOM);
}
