// kaoya.c 烤鸭

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("饭", ({"fan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "香喷喷的饭菜。\n");
		set("unit", "只");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
