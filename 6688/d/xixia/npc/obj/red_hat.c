#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIR"红缨冠"NOR, ({ "red hat","hat" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "feather");
                set("value",1000);
                set("armor_prop/armor", 2);
                set("unequip_msg", "$N轻轻地把$n从头上除了下来。\n");
        }
        setup();
}
