// hand_axe.c
#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
inherit F_UNIQUE;

void create()
{
        set_name(YEL"满天花流泪"NOR, ({ "dagger" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("unpawnable",1);
		set("no_paimai",1);
                set("material", "steel");
                set("long",
                        "这是唐梦的自定兵器,近战具有相当强的杀伤力。\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入腰间的剑套内。\n");
                set("weapon_prop/attack", 3);
                set("weapon_prop/defense", -2);
		set("replica_ob","/obj/weapon/dagger.c");
        }
	init_dagger(34);
        setup();
}
