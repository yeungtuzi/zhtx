// thin_sword.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("覆雨剑", ({ "rain sword", "sword" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("rigidity",5000000); //后面加了个零,省的老被削断了
		set("unit", "把");
		set("value", 0);
		set("material", "steel");
		set("long", "这就是名震天下的覆雨剑，剑长三尺三分，剑身既薄且窄，轻飘飘的似若无物。\n");
		set("wield_msg", GRN"$N手中爆起一天闪烁无定，眩人眼目的光点，鲜花般盛放着。\n"NOR);
		set("unequip_msg", GRN"光雨悄然散去，$n归入鞘中。\n"NOR);		
		set("weapon_prop/attack", 50);
		set("weapon_prop/parry", 50);		
	}
	init_sword(120);
	setup();
}
