//《雪山飞狐》
//book5 by tlang

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"雪山飞狐"NOR, ({"flying fox","book"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是金庸先生写的书，散落各处，很珍贵的。\n");
		set("unit", "本");
		set("value", 100);
		set("material", "paper");
	}
	setup();
}

