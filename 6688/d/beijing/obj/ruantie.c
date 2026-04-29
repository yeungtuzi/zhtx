// ruantie.c

inherit ITEM;

void create()
{
	set_name("软铁", ({ "ruantie" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块软铁，可以用来打造兵器。\n");
		set("value", 100);
	}
}


