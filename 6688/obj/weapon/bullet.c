// /obj/weapon/bullet.c

#include <weapon.h>

inherit COMBINED_ITEM;
//inherit BULLET;
//inherit THROWING;

void create()
{
	set_name("子弹", ({ "bullet" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("short", "7.62mm步枪子弹(bullet)");
		set("long", "装在枪(gun)里发射出去才有用的子弹.\n");
                set("type", "7.62mm步枪子弹");
		set("unit", "些");
		set("base_unit", "颗");
		set("base_weight", 20);
		set("base_value", 50);
        }
	set_amount(1);
	setup();
}

