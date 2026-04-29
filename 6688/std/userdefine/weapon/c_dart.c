#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("比武用镖", ({ "dart" }) );
	set("no_decrease",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "一枝武者自己打造的回旋镖, 十分常见的暗器。\n");
                set("value", 50);
		set("base_unit","枚");
               	set("material", "steel");
        }
        set_amount(1);
        init_throwing(15);
        setup();
}
