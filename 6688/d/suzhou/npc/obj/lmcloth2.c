//liumang cloth
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIC"牛崽衣"NOR, ({ "niuzai yi","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一件手工精细的衣服，是流氓们打架时穿的，可以加防御。\n");
		set("unit", "件");
		set("material", "silk");
		set("armor_prop/armor", 10);
		set("armor_prop/courage", 5);
                set("armor_prop/personality", -2);

		set("value",10000);
	}
	setup();
}
