// Room: /d/mingjiao/mjfengmen.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "松林");
    set("long", @LONG
这是一条松林中的小道，曲曲折折地通向前方。
LONG
    );

    set("exits", ([
        "southeast" : __DIR__"mjsimen1",
        "northwest" : __DIR__"mjtianmen1",
    ]));

    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}

