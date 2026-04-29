// /d/xizang/ice8.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中,凛冽的寒风穿透层层叠叠的冰柱,如刀削一样
掠过你的脸颊,但你已冻得麻木了,并不觉得如何疼痛.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ice6",
        "east" : __DIR__"ice1",
       "north" : __DIR__"ice4",
       "south" : __DIR__"ice3",
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
