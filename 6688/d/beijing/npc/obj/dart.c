#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("比武用镖", ({ "dart" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "一枝专供比武用的飞镖, 十分常见的暗器。\n");
                set("unit", "些");
                set("base_unit", "枝");
                set("base_weight", 40);
	set("material", "steel");
                set("value", 50);
        }
        set_amount(1);
        init_throwing(15);
        setup();
}
