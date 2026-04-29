// /d/xizang/npc/puying.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("卜鹰", ({ "pu ying", "puying", "ying" }) );
        set("title", "鹰记老板");
        set("gender", "男性" );
        set("age", 28);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 25);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long", @LONG
    卜鹰身材高大,头顶微秃,一个长长的鼻子末端略有些钩形,眼眶深陷,双
目炯炯有神,一望就知不是中原人.虽然他看起来相当英俊, 但总给人一点神
秘莫测的感觉.
LONG
);
        set("combat_exp", 1200000);
        set("attitude", "friendly");
        set("inquiry", ([
                "宝藏" : "我正在招募寻宝者,只要找到宝藏大家就都不用受穷了.\n",
                "寻宝" : "任何人只要成功地找到昆仑之墟,我就给他奖励.\n",
                "奖励" : (: ask_me :),
            "昆仑之墟" : "从采石场往南,是雅鲁藏布江,溯江而上去找吧.\n",
        ]) );
        set("env/wimpy", 70);
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 3000);
        set("force", 6000);             
        set("force_factor", 40);
        set("max_mana", 1000);
        set("mana", 1000);
        set("mana_factor", 3);
	set_skill("literate", 100);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 180);
        set_skill("flysword", 200);
        set_skill("flysteps", 200);
        set_skill("fireforce", 200);
	set_skill("cloudhand", 200);
	set_skill("sword", 200);
	set_skill("move", 200);
	set_skill("unarmed", 200);
        map_skill("force", "fireforce");
        map_skill("dodge", "flysteps");
	map_skill("move", "flysteps");
	map_skill("parry", "flysword");
	map_skill("sword", "flysword");
	map_skill("unarmed", "cloudhand");

        create_family("黑道盟", 6, "副盟主");
	set("class", "engineer");

        setup();
        
        carry_object(__DIR__"obj/smoke")->wield();
        carry_object(OBJ_DIR"cloth")->wear();

        add_money("gold", 10);
}

int accept_fight(object me)
{
        command("say 咦... 要打就真打吧，光是较量多没意思？");
        command("grin");
        kill_ob(me);
        return 1;
}

string ask_me(object who)
{
        object item;
        who = this_player();
        if ( !who->query("marks/昆仑之墟") )
                return "你还没有找到昆仑之墟,就想讨赏吗?\n";
        if ( who->query("marks/卜鹰") )
                return "作我的弟子,不可以这么贪心.\n";
        command("say 嗯,你果然不是一般人,作我的弟子吧!");
        who->set("marks/卜鹰", 1);
        item = new (GOLD_OB);
        item -> set_amount(20);
        item -> move(who);
        return "这些钱是给你的奖励.\n";
}

void attempt_apprentice(object me)
{
        if( !me->query("marks/卜鹰")){
          command("say 我有何得何能,也敢开山收徒弟?\n");
          return;
        }
        command("say 作我的弟子,最忌到处招摇撞骗,欺负穷人,你要记住!\n");
        return;
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/卜鹰")){
          command("say 我有何得何能,也敢开山收徒弟?\n");
          return 0;
        }
        return 1;
}

int accept_learn(object me, string skill)
{
	if( (int)me->query_skill(skill, 1) > me->query("marks/卜鹰") *10) {
	tell_object(me, "你整天缠着我干什么,还不快把探险成绩汇报上来!\n");
	return 0;
//notify_fail("你整天缠着我干什么,还不快把探险成绩汇报上来!\n");
	}
	return 1;
}
