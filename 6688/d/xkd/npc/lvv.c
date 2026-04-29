#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("百里", ({ "bai li", "lvv" }));
        set("nickname", HIR"绝尘一笑，弹指间风云失色"NOR);
        set("long", 
"他就是传说中不折不扣的大米——百里，其实要说他本来也不至于沦落到此等境地，\n"
"只是由于师道中落，日渐衰败，桃花岛已然不像从前那么风光，加之后来被乾坤教吞\n"
"并，他不得不一身担负起复兴师门的重任，无奈天不随人愿，生活拮据的他甚至沦落\n"
"到在江湖上给人弹兵器混口饭吃。在一场惨绝人寰的武林浩劫之后，就再也没有他的\n"
"消息了。他的一生也许是一段传奇，也许是一场悲剧，但武林后辈们依旧津津乐道着\n"
"他曾经的笑傲江湖，生平快事。\n");



        set("gender", "男性");
        set("age", 60);
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

        set_skill("spring-blade", 220);
        set_skill("blade", 220);
        set_skill("celestial", 200);
        set_skill("force", 200);
        set_skill("celestrike", 150);
        set_skill("music", 200);
        set_skill("pyrobat-steps",200);
        set_skill("six-chaos-sword",200);
        set_skill("taohua-force",200);
        set_skill("fonxansword",200);
        set_skill("fuliu-jian",200);
        set_skill("fall-steps",200);
        set_skill("spicyclaw", 200);
        set_skill("cuixin-zhang", 200);
        set_skill("dodge", 200);
        set_skill("sword", 200);
        set_skill("claw", 200);
        set_skill("yanxing-dao", 200);
        set_skill("strike", 200);
        set_skill("move", 200);
        set_skill("perception", 200);



        map_skill("force", "taohua-force");
        map_skill("claw", "spicyclaw");
        map_skill("strike", "cuixin-zhang");
        map_skill("sword", "fuliu-jian");
        map_skill("blade", "spring-blade");
        map_skill("parry", "fonxansword");
        map_skill("dodge", "fall-steps");
        map_skill("move", "pyrobat-steps");

        prepare_skill("claw", "spicyclaw");
        prepare_skill("strike", "cuixin-zhang");
        create_family("乾坤教", 2, "天龙大护法");
        set("title",BLK"乾坤教"+HIB"天龙"+HIW"大护法"NOR);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );        


        set("inquiry", ([
                "道全": 
"他是我们的大天神，纵横II的复兴就指望他了！！\n",
                "晓风残月": 
"那是大天神啊!你问他干什么，记着，千万不要在酒桌上和他讨价还价！！！\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

//   carry_object("/d/qiankun/obj/weapon/xiaolou")->wield();

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
                say("本派的宝库据说有很多宝物，据说已经有不少人前去探险了，这些贪心的家伙！！\n");
        }
        else
        if( random(10) > 8)
        {
                say("据说晚月庄可以召唤神物了，也不知道本派什么时候才有这样的神物护佑。\n");
        }
        else if (random(2) >0 )
        {
                command("poke1 " + ob->query("id"));
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

        if( (int)ob->query_skill("force",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"内功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query_skill("sword",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"剑法修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩子，历经千辛万苦，你还是找到这里来了！");
                command("say 本派虽为邪派，却也不做为非作歹、丧尽天良的恶事！");
                command("say 今后在江湖中一定还要替天行道，切莫让那些所谓的名门正派小觑了咱们！");
                command("recruit " + ob->query("id") );
                ob->set("title", BLK"乾坤教"+HIB"天煞"+HIW"大护法"NOR);
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

