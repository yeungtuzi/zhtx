// Room: /open/hihi/innup.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"酒店二楼"NOR);
	set("long", @LONG
你来到了酒店二楼，这里是供一些有名气的侠客做聚会酒宴用的，只有
你的名气足够大，你才能在这里定做筵席。当然，如果你是一个豪富，自然
也能在这里安安稳稳的喝酒，还有可能得到特别服务呢！往上去三楼的楼梯
口处有一扇门(door).
LONG
	);
	/*set("no_fight", "0");*/
	set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"inn",
//      "up" : __DIR__"inn3f",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/wgirl" : 2,
		__DIR__"npc/mboss" : 1,
		]));
	
	setup();
	
}
void init()
{
     
	add_action("do_up", "up");
}
int do_up()
{        int i;
	 object *inv;        
	 object me;
	 object room;
	 me = this_player();
	 inv = all_inventory(me);
	 for(i=0; i<sizeof(inv); i++)
		{        if((string)(inv[i]->query("id")) == "key")
	{       message_vision("$N打开小门向上走去.\n",me);
	       room = load_object(__DIR__"inn3f");
	       if(room) me->move(room);
		return 1;
	}        }
	return notify_fail("你没有门的钥匙!!!\n");
	
}
