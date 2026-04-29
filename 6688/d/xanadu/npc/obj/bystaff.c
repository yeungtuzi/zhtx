
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name(HIY"白云锡杖"NOR, ({ "tianbing baodao", "baodao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 0);
		set("material", "tin");
		set("long", "故老相传，这就是当初创立白云杖法时所用之锡杖，上面克满了密宗经文。\n");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("weapon_prop/parry",50);
	}
        init_hammer(120);
	setup();
}
