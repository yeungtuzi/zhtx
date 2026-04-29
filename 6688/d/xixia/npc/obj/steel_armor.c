#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIW"精钢战甲"NOR, ({ "steel armor", "armor" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
		set("long", "这件铠甲是用上好的纯金打造的，寒光闪闪。\n");
                set("value",5000);
                set("armor_prop/armor", 35);
                set("armor_prop/dodge", -5);
		set("wear_msg", "$N穿上一件铠甲，登时威风凛凛。\n");
		set("unequip_msg", "$N将身上的铠甲脱了下来。\n");
        }
        setup();
}

