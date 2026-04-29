// /d/xizang/xueshan3.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "雪山之顶");
        set("long", @LONG
这里是由川入藏必经的大雪山,你一爬到山顶,四望是一片白皑皑终
年不化的积雪,一条冰川由山顶向南延伸而下,就象是条白龙, 沿着冰川
伸展的方向似乎有条小路,不过进藏的路是在西边,向东下山的话就是西
川地界了.这里气候寒冷,不可久留.
LONG
        );
        set("exits", ([
 "westdown"  : __DIR__"xueshan4",
 "eastdown"  : __DIR__"xueshan2",
 "south"     : __DIR__"road",
]));
        set("outdoors", "xizang");
        setup();
//        replace_program(ROOM);
}
// 这里增加冷的效果

void init()
{
        object ob;
        if( interactive( ob = this_player()))
        {
        remove_call_out("freezing");
        call_out("freezing", 1, ob);
        }
}
