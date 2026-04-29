
inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rqhhtoxsh1",
//	"westup"   : "/d/xingxiu/tianroad1",
	"westup"   : "/d/xingxiu/xxh1",
]));

	setup();
	replace_program(ROOM);
}
