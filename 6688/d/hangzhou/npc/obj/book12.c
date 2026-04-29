//《倚天屠龙记》
//book12 by tlang

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"倚天屠龙记"NOR, ({"stories of killing dragon","book"}));
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

