// /d/xizang/ice1.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中,四下望去,都是层层叠叠晶莹剔透的冰柱.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ice8",
        "east" : __DIR__"ice6",
       "north" : __DIR__"ice9",
       "south" : __DIR__"ruin",
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
