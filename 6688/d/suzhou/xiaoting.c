//ROOM: d/suzhou/xiaoting.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"小亭"NOR);
	set("long", @LONG
	   这是一个供行人休息的亭子。一个小贩在大声吆喝着。从小亭里往外看，
可以发现一条大道通向一座宏伟的庄院。北边的宁王府暂时不开放。
LONG
	);
	set("sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"szroad4",
//		"north" : "/d/guard/sgroad",
	]));
	set("objects", ([
		__DIR__"npc/ren2" : 1,
		__DIR__"npc/xiaofan" : 1,
	]));
	setup();
}





