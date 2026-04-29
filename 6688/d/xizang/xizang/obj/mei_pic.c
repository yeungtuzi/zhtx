// /d/xizang/npc/obj/mei_pic.c

inherit ITEM;

void create()
{
	set_name("小梅的画像", ({ "picture", "mei_pic" }));
	set_weight(20);
	set("character", "小梅");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long","这是铁笑画的小梅的画像.\n");
		set("value", 0);
	}
}
