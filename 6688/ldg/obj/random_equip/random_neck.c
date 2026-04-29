//random cloth
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_NECK;

void create()
{
	set_name("围巾", ({ "scarf" }) );
	set_weight(100);
	set("random",1);
	set("unit", "件");
	set("material", "blacksilk");
	setup();
}
