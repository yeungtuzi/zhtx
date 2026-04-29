inherit NPC;

void create()
{
	set_name("土蕃武士", ({ "tubo fighter", "fighter" }));
	set("age", 18+random(29));
	set("gender", "男性");
	set("long", @LONG
这次西藏宗赞王子来西夏应征驸马，身边着实带了不少武士，一个
个都是凶巴巴的。
LONG);
	set("attitude", "peaceful");
	set("cor", 35);

	set("max_kee", 700);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 5);
	set("combat_exp", 120000);
	set("shen_type", -1);
	set("bellicosity", 500);

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("bolomiduo", 80);
	set_skill("iron-cloth", 70);
	set_skill("dodge", 90);
	set_skill("move", 35);
	set_skill("parry", 100);
	set_skill("blade", 100);

	setup();

	carry_object(__DIR__"obj/zangdao")->wield();
	carry_object("obj/cloth")->wear();
}
