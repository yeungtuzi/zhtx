//random cloth
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_SURCOAT;

void create()
{
	set_name("披风", ({ "cloak" }) );
	set_weight(100);
	set("random",1);
	set("unit", "件");
	set("material", "blacksilk");
	setup();
}
