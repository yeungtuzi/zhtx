inherit NPC;

void create()
{
	set_name("察哥", ({ "cha ge", "cha"}));
	set("long", @LONG
察哥是当今皇帝的叔父，很有才干，现任兵部尚书。
LONG);
	set("gender", "男性");
	set("title", "兵部尚书");
	set("nickname", "皇叔");
	set("age", 56);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 34);
	set("lea", 45);
	set("elo", 30);
	set("per", 24);
	set("con", 22);

	set("max_kee", 500);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 2);

	set("combat_exp", 100000);
	set("score", 30);

	set_skill("force", 80);
	set_skill("unarmed", 120);
	set_skill("dodge", 100);
	set_skill("literate", 220);
	set_skill("parry", 100);

	setup();

	carry_object(__DIR__"obj/jinpao")->wear();
        add_money("gold",1);
}
