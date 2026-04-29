#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("渡傲长老", ({ "duou zhanglao", "duou" }));
        set("nickname", HIY"极品大米"NOR);
        set("long", 
"他是少林派近年来为数不多的高手之一。随着华山派，步玄派日益崛起，做为武\n"
"林泰斗的少林派近来势力逐渐削弱。渡傲长老则依然用自己扎实醇正的少林绝学\n"
"捍卫着少林的地位和尊严，将来犯之敌数次击退，并将少林武学发扬光大，重振\n"
"少林雄风。随着自身武功进境逐渐加强，戾气也越积越多，为了避免当年少林前\n"
"辈的惨剧再一次发生，他最终听从了扫地僧的劝告，硬生生散去一身武功，甘于\n"
"从位高权重的少林达摩堂首座降为藏经阁扫地的小沙弥，苦心钻研佛法，终于在\n"
"不惑之年达到“无我无相”的境界，据说他的武学修为实已不在早年间归隐的扫\n"
"地僧之下。\n");

        set("gender", "男性");
        set("class", "bonze");
        set("age", 100);
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
        set_skill("cuff", 250);
        set_skill("dagou-bang", 200);
        set_skill("huntian-qigong", 200);
        set_skill("force", 250);
        set_skill("strike", 250);
        set_skill("hunyuan-yiqi", 250);
        set_skill("buddhism", 400);
        set_skill("jingang-quan", 250);
        set_skill("banruo-zhang", 250);
        set_skill("xianglong-zhang",200);
        set_skill("literate",300);
        set_skill("move", 200);
        set_skill("parry", 250);
        set_skill("shaolin-shenfa", 220);
        set_skill("xiaoyaoyou", 200);
        set_skill("sword", 220);
        set_skill("damo-jian", 220);
        set_skill("shexing-shou", 200);
        set_skill("hand", 200);
        set_skill("checking", 200);
        set_skill("begging", 200);
        set_skill("blade", 200);
        set_skill("liuhe-dao", 200);
        set_skill("cibei-dao", 220);
        set_skill("staff", 200);


        map_skill("force", "hunyuan-yiqi");
        map_skill("cuff", "jingang-quan");
        map_skill("strike", "banruo-zhang");
        map_skill("sword", "damo-jian");
        map_skill("staff", "dagou-bang");
        map_skill("blade", "cibei-dao");
        map_skill("hand", "shexing-shou");
        map_skill("parry", "jingang-quan");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("move", "xiaoyaoyou");

        prepare_skill("cuff", "jingang-quan");
        prepare_skill("strike", "banruo-zhang");

        create_family("少林派", 2, "扫地和尚");
        set("title",HIC "少林派" NOR + HIR "扫地"+HIW"老沙弥" NOR);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );        


        set("inquiry", ([
                "道全": 
"哎~~~~~要不是他，少林现在还不知道在哪里混呢。\n",
                "晓风残月": 
"那是大天神啊!你问他干什么，记着，千万不要在酒桌上和他讨价还价！！！\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

        carry_object("/d/qiankun/obj/weapon/tieluohan")->wear();

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
                say("这位施主，还是尽早归依我佛，才能修得正道。\n");
        }
        else
        if( random(10) > 8)
        {
                say("据说扫地僧很快会重出江湖了，但他似乎已经超越了佛的境界，想胜他真的难于上青天啊

。\n");
        }
        else if (random(2) >0 )
        {
                command("buddhi " + ob->query("id"));
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
        if( (int)ob->query_skill("cuff",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"拳法修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query_skill("strike",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"掌法修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
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
                command("say 阿弥陀佛，善哉善哉！");
                command("say 既然如此，为老衲就收下你了！！");
                command("say 今后在武林中切不可好勇斗狠，为非作歹，否则将严惩不戒！！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIC"少林派"+HIR"扫地"+HIW"僧人"NOR);
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

