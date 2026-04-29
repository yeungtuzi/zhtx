// /d/xizang/ice9.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中的空地,你身边是一个滚烫的火山口,炽热的岩浆
在里面翻滚流动,不时冒出几个气泡.你觉得脚下的岩石不断震动, 似乎马上就
要塌落进火山口里去.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ice4",
        "east" : __DIR__"ice2",
       "north" : __DIR__"ruin",
       "south" : __DIR__"ice1",
]));
        set("outdoors", "xizang");
        setup();
}

void init()
{
        object ob;
//        int water, food, force, kee, temp;
        if( interactive( ob = this_player()))
        {
        remove_call_out("freezing");
//        call_out("freezing", 1, ob);
        }
}
