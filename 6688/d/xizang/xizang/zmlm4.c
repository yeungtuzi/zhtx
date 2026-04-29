// /d/xizang/zmlm4.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/zmlm.h"

void create()
{
        set("short", "珠穆朗玛峰顶");
        set("long", @LONG
这里可说是天下最高的地方,你伸出手,觉得仿佛可以触摸到天顶.四外寂寥无人,
也没有其它生物,你觉得有些孤独,只想赶快回到山下热闹的世界中去.
LONG
        );
        set("exits", ([
		"northdown" : __DIR__"zmlm3",
]));
	set("outdoors", "xizang");
        setup();
}

void init()
{
        object ob;
        if( interactive( ob = this_player()))
        {
	remove_call_out("freezing");
        remove_call_out("choke");
        call_out("choke", 1, ob);
        }
}
