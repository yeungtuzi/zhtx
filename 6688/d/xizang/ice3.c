// /d/xizang/ice3.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中,透过层层叠叠的冰柱,远远望见一弯冷月似笑
非笑地挂在山顶.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ice7",
        "east" : __DIR__"ruin",
       "north" : __DIR__"ice8",
       "south" : __DIR__"ice4",
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
