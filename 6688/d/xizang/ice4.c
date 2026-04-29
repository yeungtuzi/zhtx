// /d/xizang/ice4.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中的空地,你身边是裸露的暗青色山岩,仿佛一群张牙
舞爪地跃动着的恶魔,正准备在下一秒钟向你猛扑过来.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ice2",
        "east" : __DIR__"ice9",
       "north" : __DIR__"ice3",
       "south" : __DIR__"m_road1",
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
        call_out("freezing", 1, ob);
        }
}
