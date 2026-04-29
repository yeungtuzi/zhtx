// /d/xizang/inn1.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long", @LONG
这是是客房
LONG
        );

        set("exits", ([
                "west" : __DIR__"inn",
                ]) );
        setup();
}
