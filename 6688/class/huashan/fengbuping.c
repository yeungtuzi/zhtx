// fengbuping.c -封不平
#include <ansi.h>
inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;

int ask_xueyi();

void create()
{
        set_name("封不平",({"feng buping","buping","feng"}));
        set("long",
                "华山派剑宗传人。\n"
                "他是华山剑宗的第一高手。剑气之争剑宗一败涂地，封不平在此隐居苦练。 \n"
                "力图重新夺会华山掌门的位子，据说现在的封不平，功夫不在华山派当今   \n"
                "掌门---“君子剑”岳不群之下，是江湖中第一流的高手。"
                );
	set("title", GRN "华山" NOR + YEL "剑宗" NOR + CYN "掌门" NOR);
        set("marks/ningssword",1);
        set("gender", "男性");
        set("age", 40);
	set("feilong", 1);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("max_kee",  5000);
        set("max_gin", 4000);
        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 150);
        set("combat_exp", 8500000);
        set("score", 10000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hasten" :),
        }) );

          set_skill("force", 180);
          set_skill("huashan-neigong", 180);
        set_skill("dodge", 200);
        set_skill("huashan-shenfa", 200);
        set_skill("parry", 180);
        set_skill("sword", 220);
        set_skill("huashan-jianfa", 200);
        set_skill("wind-sword", 200);        
        set_skill("strike", 150);
        set_skill("hunyuan-zhang", 150);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "wind-sword");
        map_skill("sword", "wind-sword");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派剑宗" , 18, "弟子");
        set("inquiry", ([
                "学艺" : (: ask_xueyi :),
        ]) );

        setup();
	set_temp("apply/armor_vs_force",100);
	set_temp("apply/armor",150);
	set_temp("apply/damage",30);
        carry_object("/d/huashan/npc/obj/fengsword")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}

//int accept_fight()
//{
//	command("say 我现在没空争强斗狠。");
//	return 0;
//}	

void attempt_apprentice(object ob)
{        
	if (ob->query("mark/气宗"))
	{
	     command("say "+RANK_D->query_respect(ob)+"，我与你们气宗势不两立，岂能收你为徒。");
	     return;
	}
        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
        else if ((string)ob->query("gender")=="无性" && ob->query_skill("pixie-jian")>=50)
        {
                command("say 我看你向东厂派来的奸细。");
                return;
        }
       /* if((string)ob->query("gender")=="女性")
          {
	   if( ob->query("family/family_name")=="华山派剑宗" && ob->query_skill("sword",1) > 90 && ob->query("max_force") > 800  &&   ob->query("shen") > 2000 ) {
        	   command("say 以你的资质能练到今天的地步的确不容易，我就继续指点你一下吧。");
	           command("recruit "+ob->query("id"));
 	   }

           else  command("say 我不受女弟子。姑娘，你还是拜我的内子吧！");
           return;
          }
        if((string)ob->query("gender")=="男性")
          {*/
               if ((int)ob->query_skill("huashan-jianfa",1) <100) {
                       command("say 我华山派剑宗以剑法卓绝称雄于世。");
                       command("say " + RANK_D->query_respect(ob) +
                               "是否还应该多练练自己的剑法？");
                       return;
               }
               if ((int)ob->query("shen") < 1000) {
                       command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                       command("say 在德行方面，" + RANK_D->query_respect(ob) +
                               "是否还做得不够？");
                       return;
                      }
           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("say 你今后可要惩恶扬善，旷扶正义！绝不可为非作歹，否则为师绝
不会放过你的！\n");
           command("recruit "+ob->query("id"));
           ob->set("mark/剑宗",1);

           
}

void init()
{

        object me, ob;
        mapping fam;


        ::init();
        add_action("give_quest","quest");
        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<500 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "yue buqun"))
        {
                command("say 你多次杀害好人，还屡教不改，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("shen")<10000)
                {
                        ob->set("title",GRN "华山派" NOR + YEL+"剑宗" NOR +HIG+"剑神" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "华山派" NOR + YEL+"剑宗" NOR +HIG+"剑魔" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("shen")<10000)
                {
                        student->set("title",GRN "华山派" NOR + YEL+"剑宗" NOR +HIG+"剑神" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "华山派" NOR + YEL+"剑宗" NOR+HIG+"剑魔" NOR);
                        return;
                }
}

/*void init()
{
	::init();
        add_action("give_quest", "quest");
}
*/
// if not allow quest ,then return 0
//int valid_quest() {
//	return 1;
//}


// check if bribe is valid

int valid_bribe(object who,int val) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
	return(0);
}


// called when not finish the task
int quest_punish(object who) {
	message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

