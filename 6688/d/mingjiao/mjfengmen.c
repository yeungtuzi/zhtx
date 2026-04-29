// Room: /d/mingjiao/mjfengmen.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "竹林");
    set("long", @LONG
这是一条碎石铺成的小道，曲曲折折地通向前方。两边是
密密的竹林。
LONG
    );

    set("exits", ([
        "southeast" : __DIR__"mjfengmen1",
        "northwest" : __DIR__"mjsimen1",
    ]));

    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}

