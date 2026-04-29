//by lzxx

inherit NPC;

void create()
{
	set_name("陶侍郎", ({ "tao shilang", "tao"}));
	set("long", @LONG
陶侍郎。
LONG);
	set("gender", "男性");
	set("age", 36);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 28);
	set("per", 25);
	set("con", 22);

	set("max_kee", 500);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 0);

	set("combat_exp", 100000);
	set("score", 30);

	set_skill("force", 80);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	setup();
        add_money("gold",3);
}
