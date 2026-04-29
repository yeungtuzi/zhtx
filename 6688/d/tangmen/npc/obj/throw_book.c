//throw_book.c
//written by tang

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "暗器手法", ({ "book" }) );
        	set_weight(800);
        	if ( clonep() )
               	set_default_object(__FILE__);
        	else {
               	set("unit", "本");
	             	set("long","一本讲解暗器基本使用手法的书。\n");
               	set("value", 100);
        		set("material", "paper");
                	set("skill", ([
        			"name" :        "throwing",
            			"exp_required" :  2000,
            			"sen_cost" : 30,
                    		"difficulty" : 15,
            			"max_skill" : 50
			]) );
	}
}
               