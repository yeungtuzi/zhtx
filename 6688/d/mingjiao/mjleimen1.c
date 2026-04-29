// Room: /d/mingjiao/mjdimen1.c
// Date: XXL 97/05/11

#include <room.h>
inherit ROOM;

string look_pai();

void create()
{
    set("short", "门口");
    set("long", @LONG
	前面就是明教中西域教众练功的地方了，他们性情怪异，平时总
在做些外人摸不着头脑的东西，没事不要轻易打扰他们。
LONG
    );

    set("exits", ([
        "south" : __DIR__"leishe",
        "northeast" : __DIR__"mjleimen",
    ]));


    set("objects",([
			__DIR__"npc/basutai":1,
    ]));

    set("outdoors", "mingjiao");

    setup();
    replace_program(ROOM);
}


