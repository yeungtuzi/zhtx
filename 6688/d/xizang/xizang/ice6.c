// /d/xizang/ice6.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中的空地,你脚下是软绵绵的半凝固状态的泥浆,似
乎随时会把你陷下去.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ice1",
        "east" : __DIR__"ice8",
       "north" : __DIR__"ice2",
       "south" : __DIR__"ice7",
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
