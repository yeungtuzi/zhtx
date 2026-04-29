// /obj/toy/spile.c

/* spile.c*/
#include <ansi.h>
inherit COMBINED_ITEM;

int do_eat(string);
void init();

void init()
{
        
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name( "大补丸" ,({ "spile"}));
                
        if (clonep())


                set_default_object(__FILE__);


        else {
                set("unit", "枚");
                set("base_unit", "枚");
                set("long",HIG 
"这是一枚乌黑发亮的药丸,拿在手上就能闻到一股中药的清香。\n");
                set("value", 50000);
                set("base_value", 50000);
                  set("base_weight",10);
        }
        set_amount(1);
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

       
       
        me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
       
        me->set("food", (int)me->max_food_capacity());
       
       
        message_vision(
 "$N吃下一枚大补丸，只觉得气血充盈.不再感到饥饿了! \n",me);

       add_amount(-1);	
        return 1;
}
