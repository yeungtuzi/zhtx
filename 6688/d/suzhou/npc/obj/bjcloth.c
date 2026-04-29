//biao ju cloth
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"蝶裙"NOR, ({ "die qun","girth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",YEL"这是一套用上等蚕丝做成的纱裙，由于十分轻盈，所以又叫蝶裙。\n"NOR);
		set("unit", "件");
		set("material", "silk");
		set("armor_prop/armor", 10);
		set("armor_prop/courage", 1);
                set("armor_prop/intelligence", 1);
                set("armor_prop/personality", 1);

		set("value",10000);
	}
	setup();
}
