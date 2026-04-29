// dragon_armor.c

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name( HIY "怒龙锦胄" NOR, ({ "dragon armor", "armor" }) );
         set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
                set("value",1);
		set("material", "goldsilk");
	}
	setup();
}
