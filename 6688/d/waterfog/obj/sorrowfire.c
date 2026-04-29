// sorrowfire.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("蝴□膛", ({ "sword of sorrowfire", "sword", "sorrowfire" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "参");
		set("long", "□参□□□洼ㄛ□湍□□□蝴□腔□膛［\n");
		set("value", 7800);
		set("material", "iron");
		set("wield_msg", "$N锈堤□参□洼腔$n□□忒□［\n");
		set("unwield_msg", "$N温□忒□腔$n［\n");
	}

	init_sword(74);
	setup();
}
