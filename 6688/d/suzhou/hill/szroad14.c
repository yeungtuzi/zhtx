//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山脚");
	set("long",  @LONG
	  你来到一座山的山脚，两旁春意盎然，开着一些不知名的小花，
天空不时有几只小鸟飞过，于是草丛中惊起一只野兔，飞快地跑了。
北面不远处有青山隐现，南面远处是苏杭运河。   
LONG
	);
	set("exits", ([
		"northup" : __DIR__"szroad15",
		"southwest" : __DIR__"szroad13",
]));                            
	setup();
	replace_program(ROOM);
}
