// leather.c

#include <armor.h>

inherit FINGER;

void create()
{
        set_name("七宝指环", ({ "ring" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 500);
		set("long", "七宝指环乃逍遥派掌门信物，见指环如见掌门本人。");
                set("material", "steel");
                set("unit", "枚");
                set("armor_prop/armor", 15);
        }
        setup();
}
