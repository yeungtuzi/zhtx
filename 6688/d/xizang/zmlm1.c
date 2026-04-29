// /d/xizang/zmlm1.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/zmlm.h"

void create()
{
        set("short", "死亡线");
        set("long", @LONG
这里已经接近珠穆朗玛峰顶,空气稀薄,不宜久留.
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"zmlm2",
		"northdown" : __DIR__"zmlm0",
]));
	set("outdoors", "xizang");
        setup();
//        replace_program(ROOM);
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
