#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
   	set_name("解毒丸", ({"jiedu wan", "wan"}));
   	if (clonep())
      		set_default_object(__FILE__);
   	else {
      		set("unit", "瓶");
      		set("value", 100);
		set("base_unit","颗");
		set("base_weight",1);
		set("no_sell",1);
   	}
	set_amount(1);
   	setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   	object me = this_player();

   	if(!id(arg))
       		return notify_fail("你要吃什么？\n");

	if( query_amount() )
	{
		message_vision("$N吃下一颗" + name() + "。\n", me);
   		if ((int)me->query_condition("tm_poison") > 0) 
	    	  		me->apply_condition("tm_poison", 0);
		add_amount(-1);
   	}

   	return 1;
}
