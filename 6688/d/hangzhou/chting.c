//ROOM: d/hangzhou/chting.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

void create()
{
	set("short", MAG"景芳亭"NOR);
	set("long", @LONG
	  你来到一个亭子，亭内外有不少人正在互相道珍重，其中一个少年
特别引人注目，你仔细打量，原来他是当代大词人柳永。往西北就是杭州武林
广场。西边有一个洞，里面黑黑的，什么也看不清楚。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","hangzhou"); 
	set("exits", ([
		"south" : __DIR__"h_qclu2",
		"northwest" : __DIR__"h_wlgc",
		"west" : __DIR__"midong",
]));  

	set("objects", ([
		__DIR__"npc/liuy" : 1,
]));
	set("my_target",1);
	setup();
}

/*
int valid_leave(object me,string dir)
{
        if (me->query("age") <=70  && dir == "west" )
        return notify_fail("这洞太小，你进不去。\n");
        return ::valid_leave(me,dir);
}   
*/
   
