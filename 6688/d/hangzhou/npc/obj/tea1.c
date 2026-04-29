//tea.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("龙井香茶", ({ "longjing cha", "cha" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一杯龙井茶。\n");
		set("unit", "杯");
		set("value", 520);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "tea",
		"name": "香茶",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}
