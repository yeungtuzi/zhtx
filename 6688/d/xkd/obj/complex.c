#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("慕容雨晴", ({ "murong yuqing", "complex" }));
        set("nickname", HIG"侠之大者"NOR);
        set("long", 
"丐帮在宋末元初时势力已经大不如从前，但身为炎黄子孙的他仍毅然决然的加入\n"
"了丐帮，承担起抗击鞑子，光复中华的历史使命。天资极高的他很快得到了丐帮\n"
"老帮主洪七公的赏识，一举升为丐帮九袋长老，并亲自传授之名震天下的“打狗\n"
"棒法”，成为将来丐帮新的接班人。身负重任的他不辱使命，在武林大会上连败\n"
"少林、武当众多高手，成为新一代的武林盟主，并将丐帮继续发扬光大，团结武\n"
"林中各派仁人义士，驱逐鞑虏，复兴华夏，谱写了一首可歌可泣的历史诗篇。\n");


        set("gender", "男性");
        set("class", "beggar");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("cor", 100);
        set("int", 100);
        set("spi", 100); 

        set("cps", 100); 
        set("per", 100);
        set("con", 100);
        set("kar", 100);
        set("bln", 100);

        set("kee", 10000);
        set("max_kee", 10000);
        set("gin", 5000);
        set("max_gin", 5000);
        set("sen", 5000);
        set("max_sen", 5000);
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 300);
        set("atman",8000);
        set("max_atman", 4000);
        set("mana", 8000);
        set("max_mana", 4000);
        set("combat_exp", 20000000);
        set("score", 200000);

        set("apprentice_available", 3);

        set_skill("dagou-bang", 250);
        set_skill("huntian-qigong", 250);
        set_skill("force", 250);
        set_skill("hunyuan-yiqi", 250);
        set_skill("buddhism", 300);
        set_skill("xianglong-zhang",200);
        set_skill("literate",300);
        set_skill("move", 200);
        set_skill("parry", 250);
        set_skill("xiaoyaoyou", 250);
        set_skill("shexing-shou", 200);
        set_skill("hand", 200);
        set_skill("checking", 200);
        set_skill("begging", 200);
        set_skill("blade", 200);
        set_skill("liuhe-dao", 200);
        set_skill("staff", 200);
        set_skill("strike", 250);


        map_skill("force", "hunyuan-yiqi");
        map_skill("hand", "shexing-shou");
        map_skill("strike", "xianglong-zhang");
        map_skill("staff", "dagou-bang");
        map_skill("blade", "liuhe-dao");
        map_skill("hand", "shexing-shou");
        map_skill("parry", "dagou-bang");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("move", "xiaoyaoyou");

        prepare_skill("hand", "shexing-shou");
        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 18, "传功长老");
        set("title",HIM "丐帮"+ HIY "十八代"+HIW"传功长老" NOR);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );        


        set("inquiry", ([
                "道全": 
"哎~~~~~要不是他，丐帮就被乾坤教给吞并了。\n",
                "晓风残月": 
"那是大天神啊!你问他干什么，记着，千万不要在酒桌上和他讨价还价！！！\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

        carry_object("/d/qiankun/obj/weapon/yuzhuzhang")->wear();

}


void init()
{
        object ob;
        ob = this_player();     
        ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        add_action("give_quest","quest");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( random(10) < 2)
        {
                say("不知何时才可以驱逐鞑虏，光复中华。\n");
        }
        else
        if( random(10) > 8)
        {
                say("打狗棒可是天下第一的棒法，专门打那些猪狗不如的东西。\n");
        }
        else if (random(2) >0 )
        {
                command("duck " + ob->query("id"));
        }
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 我今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{  
        if( !ob->query("got_ling") ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"怎么跑到这侠客岛上来的，这里还不是你能来的地方！！");
                return;}
        if( (int)ob->query_skill("staff",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"杖法修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query_skill("force",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"内功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩子，你这么有出息，真让我大喜过望！");
                command("say 丐帮能有你这么出色的弟子，洪老帮主生前的宿愿就可实现了！！");
                command("say 如果你胆敢在江湖中为非作歹，败坏门风，可别怪为师到时候翻脸无情！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIM"丐帮"+HIY"第十九代"+HIW"护帮弟子"NOR);
                ob->add("wlshw",-50);
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
    //            ob->set("class", "taoist");
        add("apprentice_availavble", -1);
}


// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什-
么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真-
笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

