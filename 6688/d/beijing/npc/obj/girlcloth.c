// girlcloth.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIC"宫女服"NOR, ({ "girl cloth", "cloth" }));
	set("long", "一件平常的宫女所穿的宫女服。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 2000);
		set("armor_prop/armor", 4);
                set("female_only", 1);
	}
	setup();
}
