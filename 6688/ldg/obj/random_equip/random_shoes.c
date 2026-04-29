//random boots
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_BOOTS;

void create()
{
	set_name("靴子", ({ "boots" }) );
	set_weight(100);
	set("random",1);
	set("unit", "件");
	set("material", "blacksilk");
	setup();
}
