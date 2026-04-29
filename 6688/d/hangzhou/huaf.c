// by tlang
//huaf.c
// 97.12

#include <ansi.h>
inherit ROOM;   

void create()
{
	set("short", MAG"画舫"NOR);
	set("long", @LONG
这画舫是从柳荫深处摇出来的，翠绿色的顶，朱红的栏杆，雕化的窗户里
，湘妃竹帘半卷。一个风姿绝代的美人，正做在窗口，调弄着笼中的鹦鹉。
LONG
);
	set("no_sleep_room",0);
	set("outdoors","hangzhou"); 
	set("exits", ([
		"up" : __DIR__"h_styy",
]));  

	set("objects", ([
		__DIR__"npc/hylai" : 1,
		__DIR__"npc/duan3" : 1,
		__DIR__"npc/boater" : 1,
]));
	setup();
}   
    
