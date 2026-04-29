// tea_leaf.c

#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name( "毒龙沙" , ({ "sand", "poison sand" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"有强大杀伤力的巨毒无比的毒龙沙\n");
		set("unit", "把");
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(3);
	init_throwing(50);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->apply_condition("tm_poison",random(2)+1);
	message_vision("$N中了毒龙沙上的毒！\n", victim);
}

