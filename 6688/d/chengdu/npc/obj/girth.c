// jade girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name( HIW "翡翠玉带" NOR, ({ "jade girth", "girth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 7000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("armor_prop/dodge", 5);
		set("wear_msg", "$N将$n拿出穿在身上。\n");
	}
	setup();
}
