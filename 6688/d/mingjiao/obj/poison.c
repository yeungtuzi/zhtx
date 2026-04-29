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
	message_vision("随着药力渐渐散发，$N只觉腹如刀铰，肝肠欲断！\n原来拿到的是一把用来配药攻毒的剧毒之物。\n",who);
	who->set("eff_kee",who->query("eff_kee")/2);
	who->set("eff_gin",who->query("eff_gin")/2);
	who->set("eff_sen",who->query("eff_sen")/2);
	who->set("force",0);
	who->set("mana",0);
	who->set("atmana",0);
	destruct(this_object());
	who->unconcious();
	return 1;

}
