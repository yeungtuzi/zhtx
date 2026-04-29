// Room: /d/mingjiao/nushe.c
// Date: XXL 97/05/11

#include <room.h>

inherit ROOM;

//string look_dui();

void create()
{
    set("short", "天门男舍");
    set("long", @LONG
	这房间里面光线昏暗，边上是几张床，地上放着几个蒲团。
LONG
    );

    set("exits", ([
        "south" : __DIR__"mjtianmen1",
    ]));          
    
    set("sleep_room",1);
    set("no_fight",1);
    set("no_cast",1);
    set("no_magic",1);
    set("no_poison",1);

    setup();
}


