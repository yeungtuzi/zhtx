inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("碗", ({"bowl"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("max_liquid", 3);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "soup",
		"remaining": 3,
		"drunk_apply": 0,
	]) );
}
