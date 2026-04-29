inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("酸菜鱼", ({ "suancai yu" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "酸菜和鱼为配料做的汤，味道舒服极了。\n");
		set("unit", "盘");
		set("value", 500);
		set("max_liquid", 5);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "liquid",
		"name": "酸菜鱼",
		"remaining": 5,
		"drunk_apply": 30,
	]) );
}
