// drugstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "药店");
	set("long", @LONG
你现在正站在药店里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("no_fight", "1");
        set("exits", ([
                "south"          : __DIR__"nroad1" ]) );

        set("objects", ([
		__DIR__"npc/doctor" : 1,
	]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：药。\n";
}

