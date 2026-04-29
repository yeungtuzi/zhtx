//ROOM: d/suzhou/shizx.c
//by tlang for zhang ji

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"市中心楼台"NOR);
	set("long", @LONG
	这儿是苏州城的市中心的一座高台，来来往往的行人不停的从下面经过。
一个年青人在不远处左右张望。似乎在寻找什么人，又像闲得无聊，想找点事情干。
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"down" : __DIR__"shizx",
]));
	set("objects", ([
		__DIR__"npc/zhangji" : 1,
]));
	setup();
}





