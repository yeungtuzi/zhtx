inherit NPC;

void create()
{
	set_name("值殿将军", ({ "general" }));
	set("age", 34);
	set("gender", "男性");
	set("long", "值殿将军。\n");
	set("attitude", "peaceful");

	set("str", 38);
	set("dex", 25);
	set("max_kee", 1400);
	set("combat_exp", 120000);
	set("shen_type", -1);

	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_skill("move", 85);
	set_skill("parry", 100);
	set_skill("blade", 120);

	setup();

	carry_object(__DIR__"obj/army_armor")->wear();
	carry_object(__DIR__"obj/feather_shoe")->wear();
}
