//by lzxx

inherit NPC;

void create()
{
	set_name("太监", ({ "tai jian", "jian"}));
	set("long", @LONG
宫中的太监。
LONG);
	set("gender", "中性");
	set("age", 19+random(30));
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("max_kee", 400);
	set("max_gin", 220);
	set("max_sen", 220);
	set("force", 10);
	set("max_force", 10);
	set("force_factor", 0);

	set("combat_exp", 10000);
	set("score", 3);
	set_skill("force", 10);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 40);

	setup();
 	carry_object(__DIR__"obj/taijian_cloth")->wear();
}
