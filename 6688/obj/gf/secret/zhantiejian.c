// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name( BLK "斩铁剑" NOR, ({ "zhantie jian", "sword", "jian" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", BLK"一柄宽大而且通体漆黑的长剑，异常沉重。\n"NOR);
		set("value", 0);
		set("material", "darkgold");
		set("wield_msg", "$N抽出$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入剑鞘。\n");
		set("weapon_prop/attack", 50);
		set("weapon_prop/defense", 50);
	}

        init_sword(200);
	setup();
}

