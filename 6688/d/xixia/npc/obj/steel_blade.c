#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIW"精钢战刀"NOR, ({ "steel blade", "blade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 2000);
                set("material", "steel");
                set("long", "这柄钢刀是用上好的纯金打造的，寒光闪闪。\n");
                set("wield_msg", "$N抽出一把寒光闪闪的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(30);
        setup();
}
