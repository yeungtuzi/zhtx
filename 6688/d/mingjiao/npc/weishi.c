
inherit NPC;

void create()
{
	set_name("红衣卫士", ({ "wei shi" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "正在警惕地注视着四周一切的红衣卫士。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	setup();

	carry_object(__DIR__"obj/gangdao")->wield();

}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
