// Room: /d/choyin/bridge1.c

inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"east"})
#define MENPAI "步玄派"

void create()
{
        set("short", "曲桥");
        set("long", @LONG
这是一座弯弯曲曲的曲桥，横过翠柳湖连接东岸的雨桥庄跟西岸的
乔阴县城，从这里可以欣赏翠柳湖的美景，许多睡莲散布在桥墩四周，
湖面飘著数不尽的浮萍，浮萍底下有不少□红锦鲤穿梭来去。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"s_street1",
  "east" : __DIR__"bridge2",
]));
        set("no_clean_up", 0);
        set("outdoors", "choyin");

        setup();
//        replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"