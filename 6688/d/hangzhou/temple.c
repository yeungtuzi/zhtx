//ROOM: d/hangzhou/chting.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;   

void create()
{
	set("short", RED"凤林寺"NOR);
	set("long", @LONG
	  这儿阴森恐怖，你觉得有些不对。若大的神殿里就只有一个和尚。
神像后面好象有什么东西。那和尚见你进来，也不理你，只顾抱着坛子喝酒。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","hangzhou"); 
	set("exits", ([
		"south" : __DIR__"h_nslu3",
	]));  

	set("objects", ([
		__DIR__"npc/tieshui" : 1,
]));
	setup();
}   
    
int valid_leave(object ob,string dir)
{
	message_vision("$N打开后门，走了出去。\n",ob);
	return 1;
}