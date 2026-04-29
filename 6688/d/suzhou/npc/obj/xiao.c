//OBJECT: /d/suzhou/npc/obj/xiao.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("竹萧", ({ "xiao", "zhu xiao" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", HIW"一只竹箫。可以吹(chui)。\n"NOR);
                set("value", 1000);
        }
	set("unpawnable",1);
        setup();
}                                                    

void init()
{                            
	add_action("do_chui", "chui");
}

int do_chui(string arg)
{       
	object obj=this_object();                  
	object me = this_player(); 
        
	if(!arg || arg !=obj->query("id") )
		return notify_fail("你要吹什么？\n");
	if ( (int)me->query("kee") <= 120 ) 
        { 
       		tell_object(me, YEL"你拿出一只竹萧，吹了起来，箫声如怨如恕，让人感伤不已。\n"NOR); 
		return 1;
	}
	message_vision(YEL"$N愉快地吹着竹箫。\n"NOR, me);
        me->add("gin", 1);
	me->receive_damage("kee", 1);  

        if ( random(3) == 0 ) {
                message_vision(RED"$N微微一笑，拿出竹箫开始吹，箫声旋律优美，让人叹为观止。\n"NOR,me);
                me->add("gin", 10);
		me->receive_damage("kee", 12);
                return(1);
        }
	return(1);
}
  

                 
