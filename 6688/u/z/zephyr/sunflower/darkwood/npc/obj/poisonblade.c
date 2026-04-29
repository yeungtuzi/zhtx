// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("单刀", ({ "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "iron");
                set("long", "这是一锋利的单刀，刀锋紫光闪烁。\n");
                set("wield_msg", "$N抽出一把闪烁着点点紫光的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(25);
		set("poison/type","tm_poison");
		set("poison/amount",100);

        setup();
}
