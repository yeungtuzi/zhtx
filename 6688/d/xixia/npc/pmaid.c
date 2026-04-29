//by lzxx

inherit NPC;

void create()
{
	set_name("宫女", ({ "maid" }));
	set("long", @LONG
宫中的宫女。
LONG);
	set("gender", "女性");
	set("age", 10+random(12));
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 20+random(10));

	set("max_kee", 300);
	set("max_gin", 220);
	set("max_sen", 220);
	set("force", 10);
	set("max_force", 10);
	set("force_factor", 0);

	set("combat_exp", 10000);
	set("score", 3);
	set_skill("force", 10);
	set_skill("unarmed", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);
	set_skill("sword",10);

	setup();
 	carry_object(__DIR__"obj/maid_cloth")->wear();
}
