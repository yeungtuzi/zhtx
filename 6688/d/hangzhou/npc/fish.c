//OBJECT:/d/hangzhou/npc/fish.c 
//by dwolf
//97.11.4                 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(MAG"鲤鱼"NOR, ({ "li yu", "yu" }) );
	set_weight(550);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条活泼可爱的鲤鱼 。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 6);
		set("food_supply", 50);
	}
	setup();
}

