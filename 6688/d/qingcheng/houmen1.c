// Room: /open/hihi/menfang1.c
#include <ansi.h>
inherit ROOM;
int do_break(object me);
void create()
{
	set("short", HIW"后门围墙"NOR);
	set("long", @LONG
这里是林家后门外的围墙，后门(door)关的死死的，你不可能从这里直接走进去。
还是想想别的办法吧!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"shulin",
		]));
	set("item_desc",([
		"door":"门是从里边封死的，但看起来并不是很结实，或许你可以强制打开(breakout)它.\n",
			]) );
	setup();
}
void init()
{
	add_action("do_break","breakout");
}
int do_break(object me)
{	object room;
	me = this_player();
	if((int)me->query("force")<200)
	   return notify_fail("你的内力不够.\n");
        else { if((int)me->query("max_force")<200)
        { message_vision("$N后退两步，运劲于掌，暴喝一声，双掌向门劈去.\n",me);
	 me->set("force",0);
         return notify_fail("但门丝纹未动!\n");}
        else {
	   message_vision("$N后退两步，运劲于掌，暴喝一声，双掌向门劈去.\n",me);
	  message_vision("门应声而开.\n",me);
	  me->set("force",(int)me->query("force")-200);
//          if( room == find_object(__DIR__"houmen") )                
//              room->set("exits/west",__FILE__);
//              message("vision", "后门被人从另一边打破了.\n",room );
	   set("exits/east", __DIR__"houmen");
	   set("item_desc",([
	"door": "门已经被别人打开了.\n",
		]));
          return 1;}
              }
}
