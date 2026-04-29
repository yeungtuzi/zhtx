//goldvest.c
//by tlang

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(YEL"金丝背心"NOR, ({ "gold vest", "vest" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			HIW"这件金丝背心是由金丝和石棉条混合织成的，比一般的衣服\n"
			"重了些，你用力一拉，它虽然软绵绵的，但一点也没有不结实\n"
			"的迹象。\n"NOR);
		set("unit", "件");
		set("value", 10000);
		set("material", "blacksilk");
		set("armor_prop/armor", 60);
		set("armor_prop/attack", 10);
	}
	setup();
}


