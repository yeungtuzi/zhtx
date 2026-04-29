// sword.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
// inherit F_UNIQUE;

void create()
{
        set_name( HIG "无尘剑" NOR, ({  "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "这是逍遥派历代相传的掌门信物，乃当年李逍遥在女娲洞中所找\n"
                        "到的无上宝剑。\n");
                set("value", 35000);
                set("material", "sapphire");
                set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon_prop/courage", 15);
                set("weapon_prop/intelligence", 15);
                set("weapon_prop/personality", 15);
                set("rigidity", 40);
                set("replica_ob", "/obj/longsword");
        }

        init_sword(75);
        setup();
}


