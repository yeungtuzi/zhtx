inherit ITEM;
inherit F_FOOD;

void create()
{
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盘");
		set("food_remaining", 3);
		set("food_supply", 20);
	}
	setup();
}

int finish_eat()
{
	set_name("盘子", ({"plate"}));
	set_weight(20);
	set("long", "一只蓝底儿雕花的大盘子。\n");
	return 1;
}
