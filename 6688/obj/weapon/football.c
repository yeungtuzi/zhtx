// /obj/weapon/football.c

#include <weapon.h>

//inherit BOMB;
inherit THROWING;

void create()
{
	set_name("足球", ({ "football" , "ball" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"金杯牌国际比赛用标准足球,中国制造.\n");
		set("unit", "些");
		set("base_unit", "个");
		set("base_weight", 700);
		set("base_value", 5000);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
