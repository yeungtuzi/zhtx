#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("雨伞", ({ "umbrella" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一把雨伞，外出旅行必备之物。\n");
                set("unit", "把");
                set("value", 500);
                set("material", "cloth");
        }
        init_sword(5);
        setup();
}
