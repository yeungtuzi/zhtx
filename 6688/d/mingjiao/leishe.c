// Room: /d/mingjiao/nushe.c
// Date: XXL 97/05/11

#include <room.h>

inherit ROOM;

//string look_dui();

void create()
{
    set("short", "宝相精舍");
    set("long", @LONG
	几个面目狰狞之人正盯着你看，望之不似中土人士。原来
这里是明教雷门弟子修行的地方。地上乱七八糟地摆放着一些你说
不出来用处的东西。
LONG
    );

    set("exits", ([
        "north" : __DIR__"mjleimen1",
    ]));          
    
    set("sleep_room",1);
    set("no_fight",1);
    set("no_cast",1);
    set("no_magic",1);
    set("no_poison",1);

    setup();
}


