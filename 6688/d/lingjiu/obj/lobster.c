// lobster.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("软炸虾", ({ "lobster"  }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "哇，好香好香，此时不吃，更待何时？\n");
		set("unit", "份");
		set("value", 1000);
		set("food_remaining", 5);
		set("food_supply", 30);
		set("material", "shell");
	}
	setup();
}
