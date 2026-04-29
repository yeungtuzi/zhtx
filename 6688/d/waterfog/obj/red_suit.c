// red_suit.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("□绽踞□", ({ "crimson suit", "suit" }) );
	set_weight(6500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "璃");
		set("long", "□璃□绽伎腔踞□ㄛ□□□□□□跨腔踢伎□捋阁疡［\n");
		set("material", "cloth");
		set("value", 2000);
		set("armor_prop/armor", 5);
		set("armor_prop/attack", 5);
		set("armor_prop/defense", -5);
	}
	setup();
}
