//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"客船"NOR);
	set("long", @LONG
	 一艘普通的客船，梢公不在，只有一位书生站在船头，朗声吟诗。
LONG
);
	set("exits", ([
		"up" : __DIR__"s_fqiao",
]));   
	set("objects",([
	__DIR__"npc/liuyx" : 1,
	]));
                         
	setup();
}





