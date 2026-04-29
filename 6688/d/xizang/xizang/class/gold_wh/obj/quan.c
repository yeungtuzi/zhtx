// /d/xizang/class/gold_wh/obj/quan.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("金刚圈",({"jingang quan", "quan", "ring"}));
	set_weight(28000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "个");
		set("long", "这是仿照法王弟子桑吉多所用兵器打造的金刚圈\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_hammer(57);
	setup();
}
