//OBJECT: /d/fgszhuang/npc/obj/chabei.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIW"玉瓷茶杯"NOR, ({ "yuci chabei", "chabei" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", BLK"一只千年寒玉做成的茶杯，可以喝(drink)。\n"NOR);
                set("value", 10000);
        }
	set("unpawnable",1);
	set("apply",10);
        setup();
}                                                    

void init()
{                            
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{                         
	object obj=this_object();
	object me = this_player();      
        
	if(!arg || arg!=obj->query("id") )
		return notify_fail("你要喝什么啊？\n");
	if( obj->query("apply")<1 )
		return notify_fail("都喝光了还喝？\n");
  	if ( (int)me->query("gin") <= 150  )
        { 
		add("apply",-1);
		tell_object(me, YEL"你端起一只玉瓷茶杯，喝了起来。\n"NOR); 
		return 1;
	}
	add("apply",-1);
	message_vision(YEL"$N愉快地喝着龙井茶。\n"NOR, me);
        me->add("gin", 5);
	me->add("kee", 5);   
		   
        if ( random(3) == 0 ) {
		add("apply",-1);
                message_vision(RED"$N微微一笑，拿出玉瓷茶杯开始喝，让人羡慕不已。\n"NOR,me);
                me->add("gin", 20);
		me->add("kee", 20);
                return(1);
        }
        return(1);  
}
  

                 
