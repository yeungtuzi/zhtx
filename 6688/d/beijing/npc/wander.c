
inherit NPC;

void create()
{
	set_name("流浪汉", ({ "wander"}));
	set("gender", "男性");
	set("age", 15+random(6));
	set("long",@TEXT
一个精壮的汉子，但光从穿着看，似乎比较穷困潦倒，想来应召做太监，
好渡过后半生吧。
TEXT
	);
	set("combat_exp", 50000);


	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	carry_object("/obj/cloth")->wear();
}
	
