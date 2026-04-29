//by lzxx

inherit NPC;

//void ask_me();

void create()
{
	set_name("王语嫣", ({ "wang yuyan", "wang"}));
	set("long", @LONG
肌肤胜雪，秀发如云，似嗔亦嗔，似喜亦喜。
LONG);
	set("gender", "女性");
	set("age", 19);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 15);
	set("int", 37);
	set("per", 70);
	set("con", 22);

	set("max_kee", 350);
	set("max_gin", 220);
	set("max_sen", 220);
	set("force", 10);
	set("max_force", 10);
	set("force_factor", 0);

	set("combat_exp", 10000);
	set("score", 3);

	set("inquiry", ([
	//	"武功": (: ask_me :)
	]));

	set_skill("force", 10);
	set_skill("unarmed", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);
	set_skill("sword",10);

	set_skill("sunv-xinfa", 10);

	map_skill("force", "sunv-xinfa");

	setup();
 	carry_object(__DIR__"obj/wang_cloth")->wear();
	carry_object(__DIR__"obj/goldclasp")->wear();
}
