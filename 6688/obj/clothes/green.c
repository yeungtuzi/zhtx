// /obj/clothes/green.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("淡绿色衣衫", ({ "light green cloth", "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("value", 1000);
		set("unit", "件");
		set("material", "silk");
		set("armor_prop/armor", 1);
                set("armor_apply/dodge", 5);
	}
	setup();
}
