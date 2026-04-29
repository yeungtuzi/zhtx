#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("武媚娘", ({ "wu meiniang", "charms" }));
        set("nickname", HIM"红颜一笑倾天下，身袭暖玉飘寒香"NOR);
        set("long", 
"她难道就是武林中传说了很久的天下第一美女武媚娘？就算看破红尘的僧道，定力\n"
"超凡的隐士，与她有过一面之缘后也会凡心大动。利用美色的确在江湖中为正派人\n"
"士所不齿，但她仍旧在武林中独树一帜，手中的一把魔鞭不知道令多少侠肝义胆的\n"
"志士命丧红颜。终于有一天灾难发生了，在一场武林浩劫中她已经不知所踪，有人\n"
"说她已经被众多仇家乱刀分尸，香消玉损了，更有人说她去了南海，找寻南海神尼\n"
"削发为尼，永远的避开了江湖中的恩恩怨怨，传说毕竟是传说，但她在武林中创造\n"
"的传奇不知令多少女子心驰神往。\n");



        set("gender", "女性");
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

        set_skill("mo-jian-jue", 200);
        set_skill("mo-dao-jue", 200);
        set_skill("mo-gou-jue", 200);
        set_skill("mo-bian-jue", 200);
        set_skill("mo-zhang-jue", 200);
        set_skill("mo-fu-jue", 200);
        set_skill("mo-chui-jue", 200);
        set_skill("mo-ji-jue", 200);
        set_skill("mo-cha-jue", 200);
        set_skill("mo-qiang-jue", 200);
        set_skill("tianmo-dafa", 200);
        set_skill("force", 200);
        set_skill("daguanming", 150);
        set_skill("music", 300);
        set_skill("mo-shan-jue",200);
        set_skill("iceforce",200);
        set_skill("snowwhip",200);
        set_skill("tenderzhi",200);
        set_skill("stormdance",220);
        set_skill("iceforce",200);
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 220);
        set_skill("sword", 200);
        set_skill("whip", 200);
        set_skill("strike", 200);
        set_skill("finger", 200);
        set_skill("hook", 200);
        set_skill("axe", 200);
        set_skill("hammer", 200);
        set_skill("halberd", 200);
        set_skill("fork", 200);
        set_skill("spear", 200);
        set_skill("perception", 200);
        set_skill("blade", 200);


        map_skill("force", "iceforce");
        map_skill("finger", "tenderzhi");
        map_skill("strike", "mo-zhang-jue");
        map_skill("sword", "mo-jian-jue");
        map_skill("blade", "mo-dao-jue");
        map_skill("axe", "mo-fu-jue");
        map_skill("hammer", "mo-chui-jue");
        map_skill("fork", "mo-cha-jue");
        map_skill("hook", "mo-gou-jue");
        map_skill("halberd", "mo-ji-jue");
        map_skill("spear", "mo-qiang-jue");
        map_skill("whip", "snowwhip");
        map_skill("parry", "mo-qiang-jue");
        map_skill("dodge", "stormdance");
        map_skill("move", "mo-shan-jue");

        prepare_skill("strike", "mo-zhang-jue");

        create_family("晚月庄", 2, "护庄圣女");
        set("title",HIM"晚月庄"+ HIG "护庄"+HIW"圣女"NOR);
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

//      carry_object("/d/qiankun/obj/weapon/mobian")->wield();

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
                say("据说晚月庄可以召唤神物了，咱们终于有出头的日子了！！\n");
        }
        else if (random(2) >0 )
        {
                command("lovelook " + ob->query("id"));
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
        if( (int)ob->query_skill("dodge",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"轻功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩子，历经千辛万苦，你还是找到这里来了！");
                command("say 本教虽为邪派，却也不做为非作歹、丧尽天良的恶事！");
                command("say 今后在江湖中一定还要替天行道，切莫让那些所谓的名门正派小觑了咱们！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIM"晚月庄"+HIC"灵洁"+HIW"圣女"NOR);
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

