
#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"九转金丹"NOR, ({"jin dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是胡青牛收集天地间各种灵丹妙药，并精心炼制而成的丹药。
解万毒，渡千灾，服食后功力大增。\n");
		set("value", 500000);
		set("unpawnable",1);
	}
	setup();
}

int do_eat(string arg)
{
	
	object me;
         int bak;
	
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	me = this_player();
         bak=me->query("max_force");
        
        me->add("max_force",80+random(me->query_con()));
      if (me->query("max_force")> 8000){me->set("max_force",bak);}
//        me->clear_condition();

	message_vision(HIY "$N吃下一颗九转金丹，顿然间神清气爽，功力陡增！\n" NOR, this_player());

	destruct(this_object());
	return 1;
}

