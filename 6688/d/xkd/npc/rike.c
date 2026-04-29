#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("云秋", ({ "yun qiu", "rike" }));
        set("nickname", HIG"热血衷肠，侠肝义胆"NOR);
        set("long", 
"他就是云秋，看什么看，好像天神不认识他，想知道他的来历自己去打听一下吧。\n");



        set("gender", "男性");
        set("age", 30);
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

        set_skill("hanbing-mianzhang", 200);
        set_skill("jiuyang-shengong", 200);
        set_skill("qiankun-danuoyi", 200);
        set_skill("qishang-quan", 200);
        set_skill("shenghuo-shengong", 200);
        set_skill("yueying-wubu", 200);
        set_skill("sougu", 200);
        set_skill("claw", 200);
        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("parry", 220);
        set_skill("dodge", 200);
        set_skill("move", 200);
        set_skill("fanwen", 200);
        set_skill("cuff",200);
        set_skill("hand",200);
        set_skill("strike",200);
        set_skill("claw",200);
        set_skill("dormancy",200);
        set_skill("fy-sword",200);
        set_skill("ill-quan", 200);
        set_skill("jiayiforce", 200);
        set_skill("tie-steps", 200);
        set_skill("yunhai-force", 200);


        map_skill("force", "jiuyang-shengong");
        map_skill("claw", "sougu");
        map_skill("strike", "hanbing-mianzhang");
        map_skill("sword", "shenghuo-shengong");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("dodge", "tie-steps");
        map_skill("move", "yueying-wubu");
        map_skill("cuff", "ill-quan");
        map_skill("hand", "qishang-quan");


        prepare_skill("cuff", "ill-quan");
 //       prepare_skill("hand", "qishang-quan");

        create_family("铁血大旗门", 7, "元老");
        set("title",HIY"铁血大旗门"+ HIR "副"+HIW"掌门"NOR);
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

// carry_object("/d/qiankun/obj/weapon/quan")->wield();

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
                say("庞斑是什么人物，当年还不是一样死在我的刀下！！\n");
        }
        else
        if( random(10) > 8)
        {
                say("听说现在有个玩家叫小桂子，那是我的转世，拜托大侠今后一定要多关照他，我这 先有礼了。\n");
        }
        else if (random(2) >0 )
        {
                command("pat " + ob->query("id"));
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
        if( (int)ob->query_skill("force",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"内功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}

        if( (int)ob->query("combat_exp") < 12800000 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"江湖经验还不够丰富，还需回去多点历练，否则不配做我的弟子。");
                return;}

        if( (int)ob->query_skill("cuff",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"拳法修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩子，历经千辛万苦，你还是找到这里来了！");
                command("say 咱们铁血大旗门的孩儿个个都是铁铮铮的汉子，千万记得在任何情况下都不能向别人低头！！");
                command("say 如果你敢为非作歹，为师绝对不会放过你，至少还会有天神收拾你，好自为之吧！！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIR"铁血"+HIY"大旗门"+HIW"惊世奇侠"NOR);
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

