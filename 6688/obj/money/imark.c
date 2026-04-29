// /obj/money/imark.c

inherit MONEY;

void create()
{
	set_name("帝国马克", ({"imperial mark", "imark_money", "imark"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "imark");
		set("long", 
"以沙丹大帝的名义,强制与一两银子等价的帝国货币,仅在帝国内通用.\n");
		set("unit", "张");
		set("base_value", 100);
		set("base_unit", "元");
		set("base_weight", 1);
	}
	set_amount(1);
}

