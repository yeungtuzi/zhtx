#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"无名老者"NOR, ({"wuming laozhe", "laozhe"}));
	set("age", 59);
	set("gender", "男性");
	set("long", @LONG
黑暗之中什么也看不清，唯见一对眸子精光四射。
LONG);
	set("attitude", "killer");

	set("str", 58);
	set("dex", 30);
	set("per", 25);
	set("int", 35);
	set("con", 30);
	set("cor", 30);
	set("cps", 30);
	set("elo", 30);
	set("wil", 100);	//一定要杀之

	set("max_kee", 4000);
	set("max_sen", 2000);
	set("max_gin", 2000);
	set("max_force", 3500);
	set("force", 7000);
	set("force_factor", 200);

	set("combat_exp", 5000000);
	set("shen_type", -1);
	set("shen", -100000);
	set("bellicosity", 1000);

	set("inquiry", ([
		"姑苏慕容": "不错，老夫正是姑苏慕容氏",
		"慕容博": "小子倒是很有见识，可惜可惜！",
		"斗转星移": "正是，小子倒是很有眼光，死了真是可惜！",
		"史长老": "反正你也活不多久了，史遇斗正是我杀的。",
		"原因": "对不起，这个问题的答案恐怕这辈子你是别想知道了！"
	]));

	set_temp("apply/armor", 100);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor_vs_force", 120);

	set_skill("dodge", 220);
	set_skill("move", 200);
	set_skill("parry", 220);
	set_skill("finger", 200);
	set_skill("strike", 200);
	set_skill("force", 220);
	set_skill("taohua-force", 220);
	set_skill("literate", 190);

	set_skill("taohua-force", 200);
	set_skill("nianhua-zhi", 200);
	set_skill("sanhua-zhang", 200);
	set_skill("fall-steps", 200);
	set_skill("douzhuanxingyi", 220);

	map_skill("finger", "nianhua-zhi");
	map_skill("force", "taohua-force");
	map_skill("dodge", "fall-steps");
	map_skill("strike", "sanhua-zhang");
	map_skill("parry", "douzhuanxingyi");
	
	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	setup();

	carry_object(__DIR__"obj/grey_cloth")->wear();
	carry_object("/obj/money/tenthousand-cash");
}

void init()
{
	object ob;

	if (interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (environment(ob) != environment()) return;
	tell_object(ob, HIY"你扑了个空，一时间书房里灯火尽灭，一团漆黑。"NOR);
	tell_object(ob, HIR"蓦地里，脑后传来一股劲风，不好！！！\n"NOR);

	COMBAT_D->do_attack(this_object(), ob, query_temp("weapon"));
	kill_ob(ob);
	if (ob->query_temp("littlebeggar"))
		call_out("beggar_appear", 20, this_object());
}

void beggar_appear(object me)
{
	object beggar;

	if (!me || !living(me))	return;

	message_vision(HIY"小叫花冲了进来！！！\n"NOR, me);
	beggar = new(__DIR__"beggar2");
	beggar->move(environment(me));
	beggar->kill_ob(me);

	return;
}	

void die()
{
	object ob;

	if ((ob = query_temp("last_damage_from"))
	 && ob->query_temp("tieshu") == 4)
		ob->set_temp("tieshu", 5);

	message_vision(CYN"$N一声长叹：“想不到我竟死在这里，我大燕国何时能够复兴啊！”"NOR, this_object());
	::die();
}
