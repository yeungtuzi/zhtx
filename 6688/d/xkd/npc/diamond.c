#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("雪珠", ({ "xue zhu", "diamond" }));
        set("nickname", HIW"变态防御，唯我武当"NOR);
        set("long", 
"她是武当派开山祖师张三丰的关门弟子，武当七侠名扬天下，但张三丰在垂暮之\n"
"年收了这么小徒弟，这却是鲜为人知的事情。她天赋极高，是个练武的好坯子，\n"
"而且对武当派武功的精髓理解的相当透彻，对太极剑意，太极拳宗的领悟实已超\n"
"过了当年张无忌现学现卖力退郡主赵敏手下三大高手的境界。作为武当新一代高\n"
"手的典范，传说中她的防御能力是天下第一的，没有谁能在十招只能斗败她，简\n"
"直就是名副其实的“不死鸟”，胜负未决，已然先立于不败之地了。未及三十，\n"
"便成了能和黑榜十大高手一争高下的正派人士中的中坚力量。据说当年血战接天\n"
"楼的时候众多高手中也有她一个。\n");

        set("gender", "女性");
        set("age", 35);
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
        set_skill("cuff", 200);
        set_skill("dodge", 200);
        set_skill("dugu-jiujian", 220);
        set_skill("force", 220);
        set_skill("huashan-jianfa", 200);
        set_skill("huashan-neigong", 200);
        set_skill("huashan-shenfa", 200);
        set_skill("literate",300);
        set_skill("move", 200);
        set_skill("perception", 150);
        set_skill("blade", 200);
        set_skill("spear", 200);
        set_skill("throwing", 200);
        set_skill("strike", 200);
        set_skill("whip", 200);
        set_skill("parry", 200);
        set_skill("sword", 220);
        set_skill("taiji-jian", 200);
        set_skill("taiji-quan", 200);
        set_skill("taiji-shengong", 250);
        set_skill("taoism", 250);
        set_skill("tiyunzong", 200);
        set_skill("wind-sword", 200);
        set_skill("yanshuangfei", 200);
        set_skill("hunyuan-zhang", 200);
        set_skill("poyu-quan", 200);
        set_skill("zong-jue", 300);


        map_skill("force", "taiji-shengong");
        map_skill("cuff", "taiji-quan");
        map_skill("sword", "dugu-jiujian");
        map_skill("dodge", "tiyunzong");
        map_skill("move", "yanshuangfei");
        map_skill("parry", "taiji-quan");

        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "掌门小弟子");
        set("title",HIR "武当派" NOR + HIG "奇剑飞仙"+HIW"女真人" NOR);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );        


        set("inquiry", ([
                "晓风残月": 
"那是大天神啊!你问他干什么，记着，千万不要在酒桌上和他讨价还价！！！\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

// carry_object("/d/qiankun/obj/weapon/zhenwujian")->wield();

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
                say("这位" + RANK_D->query_respect(ob)
                  +"好啊! 据说武当派现在牛得不得了，你们一定得收敛一点自己得锋芒，以免没多久就被改面了。\n");
        }
        else
        if( random(10) > 8)
        {
                say("我听说以前的沉鱼落雁又搞了个人叫闭月羞花，她还能起点好名字吗？\n");
        }
        else if (random(2) >0 )
        {
                command("fu " + ob->query("id"));
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
        if( !ob->query("mpweapon_got") ){
                command("say 本派神兵在江湖上已经失落多年，你如果能找到它我就收你为徒。");
                return;}
        if( (int)ob->query("combat_exp") < 12800000 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"江湖经验还不够丰富，还需回去多点历练，否则不配做我的弟子。");
                return;}

        if( (int)ob->query_skill("sword",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"剑术修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
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
                command("say 好孩儿，既然你的剑术和内功都已如此精进，不愧我武当派的后起之秀！");
                command("say 武当作为武林各派的泰山北斗，这个牌子千万不能在你们的手中断送！！");
                command("say 尤其咱们和华山派联盟后，更可以藐视群雄，但一定要记得收敛锋芒！！！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIR"武当"+HIG"剑派"+HIW"真人"NOR);
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

