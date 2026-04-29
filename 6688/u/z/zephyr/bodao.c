// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name( BLU "温柔" NOR, ({ "bo dao", "dao", "blade" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", BLU"有影无踪、有形无质、其快如电、柔如发丝，这柄其薄如纸的刀，叫做温柔\n"NOR);
		set("unpawnable",1);
		set("value", 0);
		set("rigidity",1000000);
		set("material", "steel");
		set("wield_msg", "$N抽出$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
		set("weapon_prop/courage", 50);
		set("weapon_prop/attack", 50);
		set("weapon_prop/defense", 50);
	}

        init_blade(300);
	setup();
}

int wield()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if( this_player()->query_skill("shortsong-blade",1) < 400)
	{
		return notify_fail("你的短歌刀法等级太低了，用不了此刀。\n");
	}
	return ::wield();
}
