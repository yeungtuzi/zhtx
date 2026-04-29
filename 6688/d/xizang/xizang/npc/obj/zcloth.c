// /d/xizang/npc/obj/zcloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("藏袍", ({ "zang pao", "robe", "cloth" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
