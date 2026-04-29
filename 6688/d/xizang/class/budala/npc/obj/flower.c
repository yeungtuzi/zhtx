// /d/xizang/class/budala/npc/obj/flower.c

#include <weapon.h>
#include <ansi.h>
 
inherit THROWING;
string* titles = ({
HIR"牡丹花"NOR,
HIR"红玫瑰"NOR,
HIW"茉莉花"NOR,
HIY"金菊花"NOR,
BLK"黑郁金香"NOR,
BLU"勿忘我"NOR
});

void create()
{
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set_name(titles[random(sizeof(titles))], 
		({"flower", "hua"}));
        	set("long", "一束美丽的鲜花\n");
        	set("unit", "把");
        	set("base_unit", "朵");
        	set("value",0);
        	set("base_value",0);
        	set("base_weight", 2);
        	set_amount(1);
	}
	init_throwing(2);
	setup();
}
