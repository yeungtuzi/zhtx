// Room: /d/quanzhou/qzroad3.c
// Date: May 7, 96   Jay
//changed by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"山路"NOR);
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。油菜花丛
中似乎有人影晃动。你不由得紧张起来。
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad2",
                "east" : __DIR__"qzroad4",
                "south" : "/d/hangzhou/ngate",
	]));

	set("outdoors", "quanzhou");
	setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("sender") && dir == "south"  
&& (present("dao zei", environment(me))))
        return notify_fail("盗贼狞笑道：乖乖地把东西留下，然后把小命留下。\n");
        return ::valid_leave(me, dir);
}



