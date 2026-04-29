// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( GRN "青松古剑" NOR, ({ "qingsong sword", "sword", "jian" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一柄宽大的长剑，剑鞘上画着一颗古松。。\n");
                set("value", 50000);
                set("material", "silver");
                set("wield_msg", "$N抽出$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入剑鞘。\n");
                set("weapon_prop/attack", 30);
                set("weapon_prop/defense", 30);
        }

        init_sword(200);
        setup();
}


