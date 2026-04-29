#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"暗门钥匙"NOR, ({"secret key"}));
	set("long",
		"这是一把金彤彤钥匙。\n");
	set("unit", "把");
	set("weight", 10);
	set("value", 100);
	set("unpawnable",1);
}

