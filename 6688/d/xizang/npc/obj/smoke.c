// /d/xizang/npc/obj/smoke.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("大漠孤烟", ({ "desert smoke", "smoke" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是卜鹰自制的长剑\n");
                set("value", 1000);
		set("rigidity", 200);
                set("material", "steel");
        }
        init_sword(70);

        set("wield_msg", "$N从青铜剑鞘中抽出一把银光闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回青铜剑鞘中。\n");

        setup();
}
