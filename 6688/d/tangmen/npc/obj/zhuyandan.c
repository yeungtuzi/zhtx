//zhuyandan.c
//by tang

#include <ansi.h>
inherit ITEM;

int do_eat(string);
void init();

void init()
{                  
        	add_action("do_eat", "eat");
}

void create()
{
        	set_name(RED "驻颜丹" NOR, ({"zhuyan dan", "dan"}));
        	set_weight(200);
        	if (clonep())
                	set_default_object(__FILE__);
        	else {
                	set("unit", "枚");
	               set("long", 
"这是一枚驻颜丹，女孩子吃了可变年轻，但听说会伤害脑子。\n");
                	set("value", 50000);
	        }

        	setup();
}

int do_eat(string arg)
{
        	object me = this_player();

	if( (string)me->query("gender")=="女性" )
	{
	        	if ( arg!="dan" && arg!="驻颜丹" && arg!="zhuyan dan" )
               	              	return notify_fail("你要吃什么？\n");

	       	if( me->query("int")>0 )	me->set("int", (int)me->query("int")-1);
        		if( me->query("mud_age")>86400 )	me->set("mud_age", (int)me->query("mud_age")-86400);
        
	        	message_vision(HIG
	 "$N吃下一枚驻颜丹，顿时年轻了许多! \n"NOR,me);

	        	destruct(this_object());
        		return 1;
	}
	tell_object(me,"女孩子才能吃驻颜丹！\n");
	return 1;
}
