
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("镣铐", ({ "liao kao", "lock", "liaokao" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("rigidity", 500000);
                set("long","这是一副精钢打造而成的镣铐，看起来十分沉重。");
        }
	init_hammer(50);
        setup();

}
