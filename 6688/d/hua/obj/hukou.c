inherit ITEM;

void create()
{
	set_name("户口卡", ({  "hukou" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个硬皮小红本。\n");
		set("unit", "本");
		set("value", 100000);
	}
}
