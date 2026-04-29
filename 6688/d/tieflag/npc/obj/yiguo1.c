inherit ITEM;
inherit F_FOOD;
#include <ansi.h>  
void create()
{
        set_name(HIB"异果"NOR, ({ "yi guo", "guo", "food"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "on");
                set("unit", "枚");
                set("long", "一种你从未见过的奇异果子。\n");
                set("value", 50000);
		set("food_remaining", 1);
		set("food_supply", 16);
        }
}  
void init()
{
   add_action("do_eat","eat");
}
int do_eat(string arg)
{       
	object me;
	int gin,kee,sen,foods,drink;
        int luck;
	me=this_player();
        luck = me->query("kar")*random(10) + 100;
	if(arg=="guo"||arg=="异果") {
        foods=(int)me->max_food_capacity();
        drink=(int)me->max_water_capacity();
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen"); 
        message_vision(HIB"$N感到快美异常，仿佛吃了什么灵丹妙药！！\n"NOR, me);
        me->set("food",foods);
        me->set("water",drink);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen); 
        me->add("cor", random(2)); 
        me->add("cps", random(2)); 
        me->add("int", random(2)); 
        me->add("lea", random(2)); 
        me->add("dex", random(2)); 
        me->add("bln", random(2)); 
        me->add("str", random(2)); 
        me->add("per", random(2)); 
        me->add("kar", random(2)); 
        me->add("spi", random(2)); 
        me->add("msc", random(2)); 
        me->add("elo", random(2)); 
        me->add("wil", random(2)); 
        me->add("vis", random(2)); 
        if(me->query("max_force") < 8000) me->add("max_force", luck); 
        if(me->query("max_mana") < 4000) me->add("max_mana", luck/2); 
        if(me->query("max_atman") < 4000) me->add("max_atman", luck/2); 
	destruct(this_object());  
	return 1; 
	}        
	return 0;
}
        

	



