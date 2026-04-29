// woodboxy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "棺材铺");
	set("long", @LONG
你现在正站在棺材铺里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "east"          : __DIR__"nwroad2" ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：棺。\n";
}

