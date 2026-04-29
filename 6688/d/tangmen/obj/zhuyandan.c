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
"这是一枚驻颜丹，女孩子吃了可长褒青春，但听说会伤害脑子，吃多了还有副作用。\n");
                        set("value", 5000);
                }

                setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if ( arg!="dan" && arg!="驻颜丹" && arg!="zhuyan dan" )
                return notify_fail("你要吃什么？\n");

        if( (string)me->query("gender")!="女性" )
	        return notify_fail("女孩子才能吃驻颜丹！\n");

        if( me->query("吃驻颜丹") > 9 )
                return notify_fail("你还要吃？不怕吃出毛病来吗？\n");
	
        if( me->query("int") < 10 )
                return notify_fail("你还要吃？不怕吃成白痴吗？\n");

        me->add("吃驻颜丹",1);
        me->add("per", 1);
        me->add("int", -1);        
      
        message_vision(HIG"$N吃下一枚驻颜丹，顿时年轻了许多! \n"NOR,me);

        destruct(this_object());
        return 1;
}
