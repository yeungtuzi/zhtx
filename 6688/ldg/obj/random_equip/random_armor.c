//random cloth
//by meteoric
#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_ARMOR;

void create()
{
	set_name("盔甲", ({ "armor" }) );
	set_weight(100);
	set("random",1);
	set("unit", "件");
	set("material", "steel");
	set("armor_prop/armor", 10);
	setup();
}
