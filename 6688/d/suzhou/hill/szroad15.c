//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long",  @LONG
	 一条缓缓上升的山道，两旁春意盎然，开着一些不知名的小花，
天空不时有几只小鸟飞过，于是草丛中惊起一只野兔，飞快地跑了。
望山上一望，隐隐约约可以看见一座庙宇。
LONG
	);
	set("exits", ([
		"northup" : __DIR__"s_hssm",
		"southdown" : __DIR__"szroad14",
]));                            
	setup();
}

int valid_leave(object ob,string dir)
{
        if( userp(ob) && random(3))
        {
                return notify_fail("你往前走着，两边的景色没有什么变化。\n");
        }
        return 1;

}



