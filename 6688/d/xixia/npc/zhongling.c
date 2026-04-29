inherit NPC;

void create()
{
	set_name("钟灵", ({ "zhong ling", "zhong"}));
	set("long", @LONG
她圆圆的脸蛋，嘴角边一个小小的酒窝，一副天真浪漫的
样子，甚是可爱。
LONG);
	set("gender", "女性");
	set("age", 16);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 28);
	set("per", 30);
	set("con", 22);

	set("max_kee", 800);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 15);

	set("combat_exp", 150000);
	set("score", 3000);
	set_skill("force", 80);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword",100);

	set_skill("yuenv-jian", 80);
	set_skill("sunv-xinfa", 100);

	map_skill("force", "sunv-xinfa");
	map_skill("sword", "yuenv-jian");
	map_skill("parry", "yuenv-jian");

	setup();
 	carry_object(__DIR__"obj/ling_cloth")->wear();
	carry_object(__DIR__"obj/shortsword")->wield();
	carry_object(__DIR__"obj/ling_shoe")->wear();
        add_money("silver",30);
}
