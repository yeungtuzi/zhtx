// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( WHT "七修剑" NOR, ({ "qixiu jian", "sword", "jian" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", WHT"一柄通体雪白的长剑，轻灵锋利。\n"NOR);
                set("value", 0);
                set("material", "darkgold");
                set("wield_msg", "$N抖出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入剑鞘。\n");
                set("weapon_prop/attack", 50);
                set("weapon_prop/defense", 60);
        }

        init_sword(200);
        setup();
}


