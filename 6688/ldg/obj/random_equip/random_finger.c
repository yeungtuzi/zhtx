//random cloth
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_FINGER;

void create()
{
	set_name("戒指", ({ "ring" }) );
	set_weight(100);
	set("random",1);
	set("unit", "件");
	set("material", "blacksilk");
	setup();
}
