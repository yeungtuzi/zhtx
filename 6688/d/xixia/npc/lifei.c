inherit NPC;

void create()
{
	set_name("丽妃", ({ "li fei", "li" }));
	set("long", @LONG
丽妃娘娘，在宫中呆闷了，出来散散心。
LONG);
	set("gender", "女性");
	set("age", 27);
	set("shen_type",1);
	set("rank_info/respect", "娘娘");
	set("attitude", "peaceful");

	set("per", 30);

	set("combat_exp", 1000);
	set("score", 3);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_skill("sword",10);

	setup();
 	carry_object(__DIR__"obj/silkdress")->wear();
}
