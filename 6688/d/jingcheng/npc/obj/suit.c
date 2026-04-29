//suit.c
// 

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("礼服", ({ "suit" }) );
	set("long","新郎倌穿的大红吉服。\n");
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
