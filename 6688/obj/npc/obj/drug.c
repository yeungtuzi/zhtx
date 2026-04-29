#include <ansi.h>

inherit ITEM;

void create()
{
   	set_name("还灵丹", ({"huanling dan", "dan"}));
   	if (clonep())
      		set_default_object(__FILE__);
   	else 
	{
		set("unit","颗");
      		set("value", 10000);
		set_weight(10);
		set("no_sell",1);
		set("unpawnable",1);
   	}
   	setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string str)
{
	string *conditions=({}),*list,arg;
	int i;
	object who;

	who = this_player();

   	if(!id(str))
       		return notify_fail("你要吃什么？\n");

	message_vision("$N吃下一颗" + name() + "。\n", who);

	list = get_dir("/daemon/condition/");

	i = sizeof(list);
	while( i-- )
	{
		arg = list[i];
		if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
			conditions += ({arg[0..strlen(arg)-3]});
	}

	i = sizeof(conditions);
	while(i--) 
	{
		if( who->query_condition(conditions[i]) > 0 )
			who->apply_condition(conditions[i],0);
	}

	destruct(this_object());
	return 1;
}
