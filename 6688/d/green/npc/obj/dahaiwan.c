//鸡汤write by lysh
// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大海碗", ({ "da hai wan", "wan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个大海碗。�\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "鸡汤",
		"remaining": 15,
		"drunk_apply": 0,
	]) );
}
