// liuhuang.c 硫磺

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY"硫磺"NOR, ({"liu huang"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块黄色的硫磺晶体。\n");
		set("unit", "块");
                set("value", 0);
	}
}
