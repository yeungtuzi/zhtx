inherit ITEM;

void create()
{
	set_name("金鲤鱼", ({"golden fish"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 100);
		set("long", "一条金色大鲤鱼。\n");
	}
	setup();
}
