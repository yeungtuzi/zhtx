
inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
	这里是铁血大旗门在草原上的根本之地，铁血弟
子已大半出行，只有一位长老在此留守。落日余晖之下，
这位年迈的长老全身笼罩在红光之中，状如天神。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"east" : "/d/road/rfttocy5",
	]));

	set("objects", ([ 
		"/class/tieflag/tieyi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
