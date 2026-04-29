// /d/xizang/class/gold_wh/npc/obj/quan.c

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("金刚圈",({"jingang quan", "quan", "ring"}));
	set_weight(68000);
	if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "个");
		set("long", "这是法王弟子桑吉多所的金刚圈\n");
		set("value", 5000);
		set("material", "steel");
	}
	init_hammer(157);
	setup();
}
