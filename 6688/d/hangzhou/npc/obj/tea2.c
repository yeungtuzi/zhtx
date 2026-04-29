// tea leaf.c

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("龙井茶叶", ({ "tea leaf", "leaf" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","才采的新茶，发出一股淡淡的香气。\n");
		set("unit", "把");
		set("value", 100);
		set("base_unit", "片");
		set("base_weight", 1);
		set("base_value", 20);
	}
	set_amount(5);
	init_throwing(1);
	setup();
}
