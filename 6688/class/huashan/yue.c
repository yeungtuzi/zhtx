 // que.c 岳不群
#include <ansi.h>
inherit "/u/z/zephyr/revengenpc.c";
//inherit "/std/char/master_yue.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

string ask_me();
void create()
{
        set_name("岳不群",({"yue buqun","yue"}));
        set("nickname", YEL "君子剑" NOR);
        set("title",GRN "华山派" NOR + YEL "第十八代" NOR+ GRN "掌门" NOR);
        set("long",
                "华山掌门岳不群，\n"
                "他今年四十多岁，人称君子剑，素以温文尔雅著称。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
	set("per", 25);
	set("no_get",1);
        set("max_kee", 3000);
        set("max_gin", 1000);
	set("max_sen", 1000);
	set("atman", 1000);
	set("max_atman", 1000);
	set("mana", 2000);
	set("max_mana", 1000);
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 200);
        set("combat_exp", 3000000);
        set("score", 50000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
//                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );
        
        set_skill("force",200);
        set_skill("zixia-shengong",200);
        set_skill("huashan-shenfa",200);
        set_skill("dodge",150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("huashan-jianfa",150);
        set_skill("purple",200);
        set_skill("literate", 200);
        set_skill("cuff", 180);
	set_skill("poyu-quan", 180);
	set_skill("strike", 150);
        set_skill("junzi-sword",200);
	set_skill("hunyuan-zhang", 180);

	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry","junzi-sword");
        map_skill("sword","junzi-sword");

        prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派气宗",18,"掌门");

        set("inquiry", ([
                "秘籍" : (: ask_me :),
        ]));

        set("book_count", 1);
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
        if (ob->query("mark/剑宗"))
        {
        	command("say "+RANK_D->query_respect(ob)+"乃是华山叛徒，我岂能收你？");
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
        if((string)ob->query("gender")=="女性")
          {
	   if( ob->query("family/family_name")=="华山派气宗" && ob->query_skill("sword",1) > 90 && ob->query("max_force") > 800  &&   ob->query("shen") > 2000 ) {
	   command("say 以你的资质能练到今天的地步的确不容易，我就继续指点你一下吧。");
		
	            command("recruit "+ob->query("id"));
                    ob->set("mark/气宗",1);    
                   
	   }

           else  command("say 我不受女弟子。姑娘，你还是拜我的内子吧！");
           return;
          }
        if((string)ob->query("gender")=="男性")
          {
               if ((int)ob->query("max_force") <200) {
                       command("say 我华山派原有剑宗、气宗之争。最终气宗为首。");
                       command("say " + RANK_D->query_respect(ob) +
                               "是否还应该多练练内力？");
                       return;
               }
               if ((int)ob->query("shen") < 1000) {
                       command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                       command("say 在德行方面，" + RANK_D->query_respect(ob) +
                               "是否还做得不够？");
                       return;
               }
           command("say 好吧，小兄弟！我就收下你了！\n");
           command("say 你今后可要惩恶扬善，旷扶正义！绝不可为非作歹，否则为师绝
不会放过你的！\n");
           command("recruit "+ob->query("id"));
           ob->set("mark/气宗",1);        

           }
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "华山派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的经书不在此处。";
        add("book_count", -1);
        ob = new(__DIR__"book-purple");
        ob->move(this_player());
        return "好吧，这本「紫气东来」你拿回去好好钻研。";
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
                        ob->set("title",GRN "华山派" NOR + YEL +"剑客" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("shen")<10000)
                {
                        student->set("title",GRN "华山派" NOR + YEL +"剑客" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
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

