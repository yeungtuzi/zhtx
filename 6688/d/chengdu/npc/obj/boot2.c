#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(YEL"追云靴"NOR, ({ "boots" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 2000);
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 5);
        }
        setup();
}
