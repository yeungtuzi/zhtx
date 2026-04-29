#include <armor.h>
#include <ansi.h>

inherit SHIELD;

void create()
{
    	set_name(HIY"黄金盾"NOR, ({ "golden shield", "shield" }) );
    	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
        	set("material", "steel");
		set("unit", "面");
        	set("value", 20000);
        	set("armor_prop/armor", 28);
        	set("armor_prop/defense", 5);
	}
	setup();
}

int wear()
{
	if( this_player()->query("combat_exp") > 500000 )
		return notify_fail("你堂堂一个武林高手，拿上盾牌象什么样？\n");
	return ::wear();
}
