#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name( HIY"黄金盔"NOR,({ "golden head","head" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","一个黄金头盔。\n");                
                set("material", "iron");
                set("value",10000);
                set("armor_prop/armor", 5);
		set("armor_prop/dodge", -5);
                set("wear_msg", "$N把一个头盔戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上除了下来。\n");
        }
        setup();
}


