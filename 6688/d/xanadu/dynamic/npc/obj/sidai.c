
#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
	set_name(HIM"无忧情丝"NOR, ({ "wuyou si","si" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一根纤细的丝带，呈银红之色，十分的美丽。\n");
		set("value", 0);
		set("unit", "根");
        	set("wield_msg","$N从腰间解下$n，轻轻地执在手中。\n");
        	set("unwield_msg", "$N把$n轻轻地缠回腰间。\n");
	}
	set("poison/amount",10000);
	set("poison/type","rose_poison");
	init_whip(120);
	setup();
}
