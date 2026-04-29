#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("云韵", ({ "yun yun", "allb" }));
        set("nickname", HIR"红颜弹指老，刹那芳华"NOR);
        set("long", 
"逍遥三派虽然分裂已久，但还是出了云韵这样一位不世出的高手，身兼逍遥派各项绝艺\n"
"使得各派无人敢小觑之，后来归隐侠客岛，不知所踪，成为武林中的一段传奇。\n");



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

        set_skill("force", 220);
        set_skill("dodge", 180);
        set_skill("literate", 200);
        set_skill("parry", 200);
        set_skill("throwing", 150);
        set_skill("perception",180);
        set_skill("hand", 200);
        set_skill("finger", 220);
        set_skill("strike", 200);
        set_skill("sword", 150);
        set_skill("axe", 150);
        set_skill("hammer", 150);
        set_skill("unarmed", 150);
        set_skill("drawing", 200);
        set_skill("qi", 200);
        set_skill("qimen-bagua", 200);
        set_skill("staff", 150);
        set_skill("whip", 150);
        set_skill("music", 200);
        set_skill("move", 180);
        set_skill("flattering", 180);
        set_skill("tianshan-zhang", 180);
        set_skill("staff", 200);
        set_skill("beiming-shengong", 200);
        set_skill("bahuang-gong", 180);
        set_skill("xiaowuxiang-gong", 180);
        set_skill("lingboweibu", 180);
        set_skill("zhemei-shou", 200);
        set_skill("liuyang-zhang", 200);
        set_skill("huagong-dafa", 200);
        set_skill("xingxiu-duzhang", 180);
        set_skill("dugong", 200);
        set_skill("fushi-dugong", 200);


        map_skill("force", "beiming-shengong");
        map_skill("dodge", "lingboweibu");
        map_skill("hand", "zhemei-shou");
        map_skill("strike", "liuyang-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("hand", "zhemei-shou");
        prepare_skill("strike", "liuyang-zhang");


        create_family("逍遥派", 2, "弟子");
        set("title",HIG"逍遥派"+ HIC "天灵"+HIW"神女"NOR);
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
                command("say 本派虽已一分为三，但其上乘武功却仍可笑傲江湖。");
                command("say 记住，咱们逍遥派一向很少参与江湖纷争，但为人还是要胸怀坦荡，不得做那些偷鸡摸狗的勾当！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIC"逍遥派"+HIY"缥缈"+HIW"奇侠"NOR);
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

