inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("汤", ({"tang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "碗");
		set("value", 1);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "汤",
		"remaining": 15,
		"drunk_apply": 4,
	]));
}
