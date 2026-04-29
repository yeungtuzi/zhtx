// Room: /d/tangmen/road2.c         
//writen by tang

inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"north"})
#define MENPAI "唐门"

void create()
{
        	set("short", "山道");
        	set("long", @LONG
这是一条偏僻的山间小道，没有任何行人，在北边好象有一座山庄，在这人烟稀少
的地方实在很罕见。
LONG
        		);
        	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"gate",
  		"east"  : __DIR__"road1",
		]));
        	set("outdoors", "tangmen");

        	setup();
//        	replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"
