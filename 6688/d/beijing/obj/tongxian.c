// ruantie.c

inherit ITEM;

void create()
{
	set_name("铜线", ({ "tongxian" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根铜线，不知道有什么用。\n");
		set("value", 100);
	}
}


