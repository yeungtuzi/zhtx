#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name( HIW"精钢战盔"NOR, ({ "steel head","head" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这个头盔是用上好的纯金打造的，寒光闪闪。\n");
                set("material", "steel");
                set("value",1000);
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", -1);
                set("wear_msg", "$N把一个头盔戴在头上，登时威风凛凛。\n");
                set("unequip_msg", "$N轻轻地把$n从头上除了下来。\n");
        }
        setup();
}


