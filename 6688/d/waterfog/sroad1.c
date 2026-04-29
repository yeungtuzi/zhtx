// Room: /d/waterfog/sroad1.c

inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"north"})
#define MENPAI "天邪派"

void create()
{
        set("short", "青石官道");
        set("long", @LONG
这是一条宽敞坚实的青石大道，大道沿著山腰往东向山下延伸，一
道长长的白石阶梯从这里往北边上山，从这里仰望阶梯的尽头有一座雄
伟的楼阁，那就是著名的「水烟阁」。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/waterfog/sroad2",
  "westdown" : "/d/road/rcstogz1",
]));
        set("outdoors", "snow");

        setup();
//        replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"