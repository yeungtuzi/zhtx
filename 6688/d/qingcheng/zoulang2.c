// Room: /open/hihi/zoulang2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"走廊"NOR);
	set("long", @LONG
这里是观中的走廊，走廊两旁的观赏性小灌木长的非常的整齐划一，给人一种
赏心悦目的美的感受。走廊南边是一个大花园，那里的花开的可真算得是姹紫嫣红
了。走廊北边有一个小房子，不过小门(door)是关着的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"huayuan",
	  "east"  : __DIR__"zoulang",
		]));
        set("objects",([
             __DIR__"npc/renhao":1,
                      ]));
	set("item_desc",([
          "door":"小门是关着的，你看不到房子里的情况.\n",	
	  "小门":"小门是关着的，你看不到房子里的情况.\n",
		]));
	setup();

}
void init()
{
        add_action("do_north", "n");
        add_action("do_north", "north");
}
int do_north(string arg)
{
        object me;
       object room;
        me = this_player();
        if((int)me->query_temp("mark/food")==1)
        {       
               me->delete_temp("mark/food");
                message_vision("$N打开小门向北走去.\n",me);

                room = load_object(__DIR__"jinbishi");
               if(room) me->move(room);
                return 1;
        }
        return 0;
}
