#include <armor.h>

inherit BOOTS;

void create()
{
    	set_name( "牛皮靴", ({ "feather shoes","shoe" }) );
    	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
        	set("material", "leather");
		set("unit", "双");
        	set("value", 2000);
        	set("armor_prop/armor", 5);
		set("wear_msg","$N将$n穿在脚上．\n");
	}
	setup();
}
