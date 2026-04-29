//liumang cloth
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"牛崽衣"NOR, ({ "niuzai yi","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一件手工精细的衣服，上面有些刺眼的图画，是流氓们打架时穿的，可以加防御。\n");
		set("unit", "件");
		set("material", "silk");
		set("armor_prop/armor", 10);
		set("armor_prop/courage", 2);
                set("armor_prop/personality", -1);

		set("value",10000);
	}
	setup();
}
