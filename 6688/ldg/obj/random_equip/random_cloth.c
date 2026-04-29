//random cloth
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_CLOTH;

void create()
{
	set_name("布衣", ({ "cloth" }) );
	set_weight(100);
	set("random",1);
	set("unit", "件");
	set("material", "blacksilk");
	set("armor_prop/armor", 1);
	setup();
}
