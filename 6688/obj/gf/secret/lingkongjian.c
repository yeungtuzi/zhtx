// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( RED "灵空剑" NOR, ({ "lingkong jian", "sword", "jian" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", RED"一柄通体血红的长剑，散发着阵阵邪气。\n"NOR);
                set("value", 0);
                set("material", "darkbloodsteel");
                set("wield_msg", "$N抖出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入剑鞘。\n");
                set("weapon_prop/attack", 50);
                set("weapon_prop/defense", 10);
        }

        init_sword(200);
        setup();
}


