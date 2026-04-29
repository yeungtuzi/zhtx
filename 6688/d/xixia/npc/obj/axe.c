#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIW"开山斧"NOR, ({ "axe" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 700);
                set("material", "iron");
                set("long", "斤重。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_axe(30);
        setup();
}
