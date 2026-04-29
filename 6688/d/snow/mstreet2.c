// Room: /d/snow/mstreet2.c

inherit ROOM;

void create()
{
	set("short", "雪亭镇街道");
	set("long", @LONG
你现在正走在雪亭镇的大街，往南直走不远处是镇上的广场，在你
的东边是一间大宅院，不过正门不在这个方向，往西是一家打铁□子，
叮叮当当的声音大老远可以听得到，街道往北边一直通往镇外。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/scavenger" : 1,
		__DIR__"npc/drunk" : 1,
]));
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"smithy",
		"south" : __DIR__"mstreet1",
		"north" : __DIR__"mstreet3",
//		"east" : "/d/duchang/daxiao.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
