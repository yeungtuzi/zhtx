/* jian.c*/

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIC"青锋剑"NOR, ({ "qingfeng jian","jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "这是一把纯钢打造的湛湛发光的长剑。\n");
                set("value", 5000);
                set("material", "steel");
                set("wield_msg", "$N「飕」地一声从腰间抽出一把亮闪闪的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入剑鞘。\n");
        }
        init_sword(45);
        setup();
}