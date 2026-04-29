// Room: /u/p/pock/bj/fire.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;35m火场[2;37;0m");
	set("long", @LONG
这里是福建宫侧的火场，是焚烧宫中垃圾废物的所在。在晚上极为僻静。
依稀可以看见火场上散布着一些乱石(stone)，没有烧完的木条(wood)，还有一
些烧好的木炭条(carbon)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 3 */
		"carbon" : "一根木炭条，可以用来涂鸦(drawing)。\n",
		"wood" : "一根没有烧完的木条，一面已经烧黑了，另一面还是很平整光滑的。\n",
		"stone" : "一些乱石头，分得很开，你如果有闲功夫，不妨把它们堆(dui)在一块。\n",
		]));
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"baohuadian",
		]));

	setup();

}
void init()
{
	add_action("do_drawing","drawing");
	add_action("do_dui","dui");
	add_action("do_cha","input");
	add_action("do_cha","cha");
}
int do_drawing(string arg)
{	object who;
        string tmp1, tmp2;
	who=this_player();
	if(!arg||arg=="")
	  return notify_fail("你要画什么？\n");
	if (sscanf(arg,"%s on %s",tmp1, tmp2) )
	  {  if(tmp1=="sparrow"&&tmp2=="wood")
	     message_vision("$N拿起木炭在木条光滑那面歪歪扭扭画了一个小雀儿，难看死了。\n",who);
	     who->set_temp("havedrawing",1);
	     return 1;
	  }	
        return notify_fail("指令格式：\ndrawing sth. on sth.\n");
}
int do_dui(string arg)			
{
	object who;
	who=this_player();
	if (!arg||arg=="")
	   return notify_fail("你要堆什么?\n");
	if(arg=="stone")
	 { message_vision("$N把周围的小石头收集了起来，堆成一小堆。\n",who);
	   who->set_temp("havedui",1);
	   return 1;
	 }
	return 0;
}
int do_cha(string arg)
{	object who,tao,room;
	who=this_player();
	tao=new(__DIR__"npc/tao");
	room=environment(who);
	if(!arg||arg=="")
	   return notify_fail("你要插什么？\n");
	if(!who->query_temp("havedui"))
	   return notify_fail("地面的泥土被烧得很结实，你插不进去。\n");
	if(arg=="wood")
	   { if(!who->query_temp("havedrawing"))
		{ message_vision("$N把木条插在石堆上。\n",who);
		  return 1;
		}
	     else if(who->query("save9nan")&&present("jiunan shitai",room))
	       {	who->delete("save9nan");
			tao->move(room);
			
	        }
             message_vision("$N把画了雀儿的木条插在石堆上。\n",who);	
	   }
	return 1;
}	