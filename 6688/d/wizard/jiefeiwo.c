inherit ROOM;

void create()
{
	set("short", "劫匪窝");
	set("long", @LONG
这是劫匪们平常呆的地方。
LONG
	);
	set("exits", ([ 
//	"west" : "/d/road/rtgtoca0",
//	"east" : "/d/road/rlytotg3",
]));
//	set("no_clean_up",1);
	setup();
	replace_program(ROOM);
}