// /d/xizang/ice7.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中,透过层层叠叠的冰柱,远远望见一轮红日喷薄
欲出,这美丽的景色使你精神为之一振,暂时忘记了身处险恶的雪山之颠.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ruin",
        "east" : __DIR__"ice3",
       "north" : __DIR__"ice6",
       "south" : __DIR__"ice2",
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
