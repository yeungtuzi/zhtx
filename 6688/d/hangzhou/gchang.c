//ROOM: d/hangzhou/gchang.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"广场"NOR);
	set("long", @LONG
	这儿就是杭州城的市中心广场了，来来往往的行人不停的经过你身边。一些
游人来来往往，也有一些卖东西的小贩在辛苦地卖东西。西边十分热闹，不时传来游
人的说话声，以及姑娘们的戏水声。东边就是著名的武林门。
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","hangzhou"); 
	set("exits", ([
                "north" : "/d/quanzhou/qzroad3",
		"west" : __DIR__"wgate",
		"south" : __DIR__"sgate",
		"east" : __DIR__"wlmen",
]));
	set("objects", ([
	
		"/d/suzhou/npc/ren" : 2,
]));
	setup();
}





