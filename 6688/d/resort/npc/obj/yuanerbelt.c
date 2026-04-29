//belt.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name(HIY"金盏花叶"NOR, ({ "yuaner's belt","belt" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "条");
                set("value", 0);
		set("no_get",1);
                set("armor_prop/armor", 80);
        }
        setup();
}
