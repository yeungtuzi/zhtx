#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("松子", ({ "songzi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把翠绿的松子,发出淡淡的松香.\n");
                set("unit", "把");
                set("base_unit", "粒");
                set("base_weight", 2);
                
        }
        set_amount(99);
        init_throwing(3);
        setup();
}
              