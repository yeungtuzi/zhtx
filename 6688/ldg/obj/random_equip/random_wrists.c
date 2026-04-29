//random wrists
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_WRISTS;

void create()
{
	set_name("手镯", ({ "bracelet" }) );
	set_weight(100);
	set("random",1);
	set("unit", "件");
	set("material", "blacksilk");
	setup();
}
