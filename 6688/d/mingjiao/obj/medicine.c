inherit ITEM;

void create()
{
	set_name("药材", ({ "yao" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "胡青牛收藏的珍贵药材。\n");
		set("unit", "把");
		set("value", 0);
	}
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object who;
	
	who = this_player();
	message_vision("$N胡乱地抓起一把药材放进了嘴里，三嚼两嚼就吞下了肚。\n",who);
	message_vision("随着药力渐渐散发，$N感觉飘飘欲仙，浑身上下充满了活力。\n",who);
	who->set("force",who->query("max_force"));
	who->set("mana",who->query("max_mana"));
	who->set("atman",who->query("max_atman"));
	destruct(this_object());
	return 1;
}
