
inherit ROOM;

void create()
{
	set("short", "唐古拉山");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northdown" : "/d/road/rkltotgl2",
	"southdown" : "/d/xizang/klroad1.c",
]));

	setup();
	replace_program(ROOM);
}
