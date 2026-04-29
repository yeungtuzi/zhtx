// /d/xizang/npc/bird.c

inherit NPC;

void create()
{
	set_name("小鸟", ({ "bird" }) );
	set("race", "野兽");
	set("age", 1+random(3));
	set("long", "一只可爱的小鸟,但是你不知道它的名字\n");
	
	set("str", 24);
	set("cor", 26);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"小鸟在你身边飞来飞去.\n",
		"小鸟发出悦耳的鸣叫声.\n",
	}) );
		
	set_temp("apply/attack", 1);
	set_temp("apply/armor", 2);

	setup();
}

