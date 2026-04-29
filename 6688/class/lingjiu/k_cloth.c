#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIM "天蚕衣" NOR, ({ "tiancan cloth", "cloth" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 60000);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 10);
		set("armor_prop/dodge", 10);
	}
	setup();
}
