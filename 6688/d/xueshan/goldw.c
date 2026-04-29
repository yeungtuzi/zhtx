// Room: /d/xueshan/goldw.c
//by tlang for 混世神剑

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", MAG"奇异世界"NOR);
	set("long", "这儿到处是好东东。左边有一道开着的门，右边也有一道门。\n");

	set("exits",([
	"west" : "/d/xueshan/foot",
	"east" : "/d/xueshan/myhell",
	]));

	create_door("east","石门","west",DOOR_CLOSED);            
	    
    	setup();
}

int valid_leave(object ob, string dir)
{
	if( !ob->query("my_hunter")  && dir=="east" )
		return notify_fail("你觉得有一种神秘的力量让你寸步难行。\n");
	return ::valid_leave(ob,dir);
}

