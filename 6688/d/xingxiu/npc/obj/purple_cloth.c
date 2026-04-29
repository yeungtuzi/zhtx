#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( MAG"紫衣"NOR, ({ "purple cloth","cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 2);
		set("armor_prop/dodge", 2);
                set("female_only", 1);
        }
        setup();
}
