//dujing.c
//written by tang

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "唐门毒经", ({ "book" }) );
        set_weight(800);
        if ( clonep() )
               	set_default_object(__FILE__);
        else 
	{
               	set("unit", "本");
		set("long","一本讲解用毒的书。\n");
               	set("value", 200);
        	set("material", "paper");
                set("skill", ([
        		"name" :        "dugong",
            		"exp_required" :  2000,
            		"sen_cost" : 30,
                    	"difficulty" : 20,
                      "base_skill":35,
            		"max_skill" : 100
			]) );
	}
}
               
