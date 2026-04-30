// /d/xizang/class/gold_wh/npc/fawang.c
// /kungfu/class/xueshan/fawang.c  金轮法王
// by secret

#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("金轮法王", ({ "jinlun fawang", "fawang" }));
        set("long",@LONG
他就是新加国师封号的密宗法王,札什伦布寺主持金轮法王.
LONG
        );
        set("title", HIY "国师" NOR);
        set("gender", "男性");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_kee", 5000);
        set("max_gin", 5000);
	set("max_sen", 5000);
        set("force", 4500);
        set("max_force", 4500);
        set("force_factor", 200);
        set("combat_exp", 3500000);
        set("score", 200000);
	set("force",8000);
	set("shen", -200000);
	set("str",60);
        set_skill("force", 180);
        set_skill("banruo", 180);
        set_skill("cuff", 180);
        set_skill("parry", 200);
        set_skill("hammer", 200);
        set_skill("literate", 150);
        set_skill("zang-buddhi", 200);
        set_skill("wuxinglun", 200 );
        map_skill("force", "banruo");
        map_skill("parry", "wuxinglun");
        map_skill("hammer", "wuxinglun");
        set_skill("move", 200);
        set_skill("yujiamu-quan", 200);
	set_skill("iron-cloth",200);
	set_skill("jin-gang",200);
	map_skill("iron-cloth","jin-gang");
        map_skill("cuff", "yujiamu-quan");
	set("marks/banruo_level", 11);
	set_temp("apply/armor_vs_force",100);
        create_family("布达拉宫", 7, "法王");
        set("class", "lama");

        setup();
        carry_object(__DIR__"obj/jinlun")->wield();
        carry_object(__DIR__"obj/pao")->wear();
        add_money("gold",1);

        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
                (: perform_action , "wuxing" :),                
        }));



}

void attempt_apprentice(object ob)
{
	if( ob->query_skill("banruo",1) < 100 )
	{
		command("say 你的武功还不够资格。");
		return;
	}

        command("smile");
        command("nod");
        command("say 你就随我学习佛法吧！");
        command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
}
void init()
{

        object ob;
        // 2026-04-30: unused variable commented out
        // mapping fam;

        ::init();
        add_action("give_quest","quest");
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    who->set("kee",0);
    return(0);
}

