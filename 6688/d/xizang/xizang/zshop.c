// /d/xizang/zshop.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "杂货店");
        set("long", @LONG
这家店是卖各种杂货的.
LONG
        );
        set("exits", ([
                "east" : __DIR__"gongqian",
        ]));
        set("objects", ([
                __DIR__"npc/zseller" :1,
		__DIR__"npc/danzhu" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
