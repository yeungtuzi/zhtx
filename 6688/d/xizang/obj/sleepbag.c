// /d/xizang/npc/obj/sleepbag.c

inherit ITEM;

void create()
{
	set("short", "宝贝,睡吧(sleeping bag)");
	set_name("睡袋", ({ "sleeping bag", "bag"}));
	set_weight(1500);
	set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", 
"这是一只狼皮缝制,内填鸭绒的睡袋,钻进里面睡一觉,一定又舒服又暖和.\n");
		set("value", 10000);
	}
}

int is_container() { return 1; }
