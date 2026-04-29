// /d/xizang/ice2.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰柱林");
        set("long", @LONG
你正站在一大片冰柱林中,四周冰柱上闪烁着淡蓝色的火花,耳边隐隐传来
轰隆隆的雷声.
LONG
        );
        set("exits", ([
        "west" : __DIR__"ice9",
        "east" : __DIR__"ice4",
       "north" : __DIR__"ice7",
       "south" : __DIR__"ice6",
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
