// /d/xizang/class/bad/npc/obj/agaric.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("灵芝", ({ "ling zhi", "agaric" }) );
	set_weight(90);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是一种生长在森林中的珍贵药材，据说对修炼内功的\n"
			"武林人士颇有帮助。\n");
		set("unit", "支");
		set("value", 30000);
		set("food_remaining", 1);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "mana": 30, "max_mana": 2000 ]) );
		set("food_supply", 100);
	}
}
