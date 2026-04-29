// xitie.c
//writteb by tang

#include <ansi.h>

inherit ITEM;

void create()
{
        	set_name("喜帖", ({"xitie"}) );
	set("long","朋友结婚，请你去作客的喜帖。\n");
        	set_weight(10);                   

        	if( clonep() )
                	set_default_object(__FILE__);
        	else 
	{
                	set("unit", "封");             
	set("no_sell",1);
                	set("material", "paper");
        	}
}

void owner_is_killed() 
{ 
	destruct(this_object()); 
}                                           

