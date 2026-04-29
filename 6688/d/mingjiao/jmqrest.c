
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "巨木旗休息室");
    set("long", @LONG
这是巨木旗的旗下弟子休息之所在，房间内光线昏暗，十分的安静。
LONG
	);
		
    set("exits", ([
        "east" : __DIR__"jmqdating",
    ]));          
    
    set("sleep_room",1);
    set("no_fight",1);
    set("no_cast",1);

    setup();
}


