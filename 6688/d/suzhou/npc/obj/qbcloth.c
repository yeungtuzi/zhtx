//qing bu cloth
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIC"青布衣衫"NOR, ({ "qingbu cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一件用用青色麻布做成的衣衫。\n"NOR);
		set("unit", "件");
		set("material", "silk");
		set("armor_prop/armor", 5);
		set("value",500);
	}
	setup();
}
