// dragon_armor.c

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name( HIY "怒龙锦胄" NOR, ({ "dragon armor", "armor" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 60000);
		set("material", "goldsilk");
		set("armor_prop/armor", 100);
                set("armor_prop/armor_vs_force", 400);
		set("armor_prop/attack", 8);
	}
	setup();
}
