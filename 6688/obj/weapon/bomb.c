// /obj/weapon/bomb.c

#include <weapon.h>

inherit BOMB;
//inherit THROWING;

void create()
{
	set_name("炸弹", ({ "bomb" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"可怕的爆炸物,最好不要老拿在手上.\n");
		set("unit", "些");
		set("base_unit", "枚");
		set("base_weight", 700);
		set("base_value", 50);
	}
	set_amount(1);
	init_bomb(20);
	setup();
}
