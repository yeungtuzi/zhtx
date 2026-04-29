//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大道");
	set("long",  @LONG
	  这是一条青石大道，两旁春意盎然，开着一些不知名的小花，天空
不时有几只小鸟飞过，于是草丛中惊起一只野兔，飞快地跑了。东边远处有座
青山隐现。南边不远是苏杭运河。      
LONG
	);
	set("exits", ([
		"south" : __DIR__"s_fqiao", 
		"east" : __DIR__"szroad12",
]));                            
	set("objects", ([
		"/d/suzhou/npc/ren2" : 1,
]));
	setup();
	replace_program(ROOM);
}
