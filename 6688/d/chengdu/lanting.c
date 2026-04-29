
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIB"兰亭"NOR);
	set("long", @LONG
	这是一座小小的亭子，是文人墨客经常聚集谈文论诗的所在,但
现在亭中只有一人在此伫立已久，似是有什么心事.
LONG
	);
        set("outdoors", "city");

	set("objects", ([
		__DIR__"npc/houxibai" : 1,
	]));

	set("exits", ([
			"south" : __DIR__"xiaoxi",
	]));

	setup();
	replace_program(ROOM);
}

