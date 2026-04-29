// /d/xizang/obj/flower.c

#include <weapon.h>
 
inherit THROWING;

void create()
{
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long",     "好美的野花啊,可是你不知道它的名字\n");
        	set("unit", "把");
        	set("base_unit", "朵");
                set("value",1);
                set("base_value",2);
        	set("base_weight", 2);
	}
	init_throwing(2);
        set_name("野花", ({"wild flower", "flower"}));
	set_amount(1);
	setup();
}
