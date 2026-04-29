// Room: /d/xueshan/myhell2.c
//by tlang for 混世神剑

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", MAG"金龙洞"NOR);
	set("long", "这儿挺阴森的。\n");

//this is just for testing	
	set("objects",([
//	"/d/xueshan/npc/goldend" : 1,
//	"/d/xueshan/npc/obj/hsword" :1,
	]));

	set("hsword_room",1);
	set("outdoors","xueshan");

   	setup();
	replace_program(ROOM);	
}
