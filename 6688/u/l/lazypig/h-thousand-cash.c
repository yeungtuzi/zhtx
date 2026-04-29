//tenthousand-cash.c

inherit MONEY;

void create()
{
set_name("一千万两银票", ({"hundr-thous-cash","htcash"}));

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "thousand-cash");
set("long", "一张面额值一千万两银子的银票。\n");
		set("unit", "叠");
set("base_value",0);
		set("base_unit", "张");
set("base_weight",100000);
	}
	set_amount(1);
}

