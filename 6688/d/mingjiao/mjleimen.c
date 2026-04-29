// Room: /d/mingjiao/mjdimen.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "草地");
    set("long", @LONG
	置身此间，仿佛来到了另外一个世界，身边花草也与中土大异。
野花艳而不香，鸟鸣怪而不和，你不禁皱了皱眉头。
LONG
    );

    set("exits", ([
        "northeast" : __DIR__"mjsimen1",
        "southwest" : __DIR__"mjleimen1",
    ]));

    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}

