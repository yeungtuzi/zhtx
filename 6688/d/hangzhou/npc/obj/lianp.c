//OBJECT:/d/hangzhou/npc/obj/lianp.c 
//by dwolf
//97.11.4                 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(MAG"莲蓬"NOR, ({ "lian peng", "lian" }) );
	set_weight(150);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个饱满的莲蓬。\n");
		set("unit", "个");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
	setup();
}

