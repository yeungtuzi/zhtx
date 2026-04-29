
inherit ITEM;

void create()
{
	set_name("金钥匙", ({"golden key","jin"}));
	set("long",
		"\n这是一把钥匙，不过小指长短，金光闪闪，却是黄金所铸。\n");
	set("unit", "把");
	set("weight", 10);
	set("no_sell",1);
	set("no_drop",1);
	set("value", 5);
	set("unpawnable",1);
}

