#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
    	set_name( GRN"绣花鞋"NOR, ({ "shoes","shoe" }) );
    	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
        	set("material", "leather");
		set("long", "这双葱绿色的绣花鞋上还绣着几朵小黄花。\n");
		set("unit", "双");
        	set("value", 2000);
        	set("armor_prop/armor", 2);
		set("wear_msg","$N将$n穿在脚上．\n");
	}
	setup();
}
