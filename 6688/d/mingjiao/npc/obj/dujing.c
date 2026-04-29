//dujing.c
//written by tang

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "难姑毒经", ({ "book" }) );
        set_weight(800);
        if ( clonep() )
               	set_default_object(__FILE__);
        else 
	{
               	set("unit", "本");
		set("long","王难姑一生心血的结晶，讲解了用毒之道。\n");
              set("value",1000);
		set("no_get",1);
        	set("material", "paper");
                set("skill", ([
        		"name" :        "dugong",
            		"exp_required" :  2000,
            		"sen_cost" : 10,
                    	"difficulty" : 10,                   
            		"max_skill" : 200,
			"base_skill" : 30,
			]) );
	}
}
               
