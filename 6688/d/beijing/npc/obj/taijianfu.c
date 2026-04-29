// taijianfu.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIC"太监服"NOR, ({ "taijianfu", "cloth" }));
	set("long", "一件小太监身上常穿的太监服。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 2000);
		set("armor_prop/armor", 4);
	}
	setup();
}
