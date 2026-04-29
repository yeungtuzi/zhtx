//《神雕侠侣》
//book8 by tlang

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"神雕侠侣"NOR, ({"couple heroes of eagle","book"}));
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

