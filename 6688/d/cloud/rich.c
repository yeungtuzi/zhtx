// rich.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "张百万家");
	set("long", @LONG
你现在正站在张百万家里
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "south" : __DIR__"eroad3",
		"north" : __DIR__"xiaoting", ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：非请莫入。\n";
}

int valid_leave(object me, string dir)
{
       if(dir == "north"){
       if( me->query_temp("enter"))
               return 1;               
       else
               return notify_fail("看看牌子,“非请莫入”。\n");
       }
       return 1;
}



