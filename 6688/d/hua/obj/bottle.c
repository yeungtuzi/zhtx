inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("奶瓶", ({  "bottle" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓶新鲜的牛奶\n");
		set("unit", "瓶");
		set("value", 20);
		set("max_liquid", 50);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "牛奶",
		"remaining": 50,
	]) );
}

void init()
{
	add_action("do_feed", "feed");
}

int do_feed(string arg)
{
	object me, *inv;
	int max_food, i;
	if (!arg) return 0;
	if (arg != "baby") {
		write("你想喂谁? \n");
		return 0;
	}
	me = this_player();
	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("id") == arg) {
			max_food = (inv[i]->query("str") - 10) * 10 + 200;
			if (inv[i]->query("food") > max_food) {
				tell_object(me, "孩子已经吃饱了, 请不要打搅他睡觉。\n");
				return 1;
			}
			message_vision("$N将奶瓶塞入婴儿嘴中, 孩子立刻不哭了, 使劲的吃起奶来。\n",me);
			inv[i]->add("food", 30);
			inv[i]->add("water",30);
			return 1;
		}
	}
	return 0;
}
