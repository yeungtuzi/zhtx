
inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"north"})
#define MENPAI "茅山派"

void create()
{
	set("short", "洞口");
	set("long", @LONG
这是一个不小的山谷，这个山洞好像是唯一的出口。山谷
里鸟语花香，就象世外桃源。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"grassland1",
  "south" : __DIR__"hole3",
]));
	set("outdoors", "taoguan");
	setup();
//        replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"