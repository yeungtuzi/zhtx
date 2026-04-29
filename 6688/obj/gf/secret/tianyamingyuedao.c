// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name( CYN "天涯明月刀" NOR, ({ "tianyamingyue dao", "blade", "dao" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一柄如天上的月亮般发亮的黑色的刀。\n");
                set("value", 50000);
                set("material", "silver");
                set("wield_msg", "$N抽出$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入刀鞘。\n");
                set("weapon_prop/attack", 30);
                set("weapon_prop/defense", 30);
        }

        init_blade(200);
        setup();
}


