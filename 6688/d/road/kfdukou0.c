
inherit ROOM;

void create()
{
	set("short", "开封渡口");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/kfdukou1",
	"south" : "/d/road/rkftodk0",
]));

	setup();
	replace_program(ROOM);
}
