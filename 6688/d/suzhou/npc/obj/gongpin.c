//gongpin.c

#include <ansi.h>

inherit ITEM;

void create()
{
    	set_name("贡品",({ "gongpin" }) );
	set("long", "扶桑国进贡的贡品，价值连城。\n");
	if( clonep() )    set_default_object(__FILE__);
       	else 
	{
		set("unit", "颗");
		set("base_weight", 200);
		set("no_sell", 1);
		set("unpawnable",1);
		set("value",100000);
		set("tactic_bonus",random(900)+100);
	}
	setup();
}


