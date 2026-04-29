// sichou.c
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIC"丝绸"NOR, ({ "sichou" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "匹");
		set("materials","cloth");
		set("long", "这是一匹上好的丝绸。\n");
		set("value", 100);
	}
}

