#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("重炮", ({ "zhong pao", "mega" }));
        set("nickname", YEL"残联副主席"NOR);
        set("long", 
"他就是号称“残联副主席”的步玄前辈，虽然除了福缘以外其他天赋没有一个超过平\n"
"平的，但是其功力远高于现任掌门骆云舟。他自小在步玄习武，出师之后依次到雪山\n"
"寺、水烟阁、武当山和华山派拜师学艺，最后在武当山上郁郁而终，始终完成不了他\n"
"的夙愿。这个人是一个悲剧人物，他见证了步玄派的荣辱兴衰，为了振兴步玄这些年\n"
"来许许多多的门人前仆后继，涌现了很多可歌可泣的英雄人物，然而始终没有一个成\n"
"功。他此刻好像在回忆着与他的好朋友云韵一起笑傲接天楼的日子。\n");



        set("gender", "男性");
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

        set_skill("mystforce", 200);
        set_skill("literate", 400);
        set_skill("mystsword", 200);
        set_skill("mysterrier", 220);
        set_skill("divine-mystsword", 200);
        set_skill("force", 200);
        set_skill("music", 200);
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 220);
        set_skill("sword", 200);
        set_skill("perception", 200);
        set_skill("calligraphy", 500);
        set_skill("chuanyun-zhi", 200);
        set_skill("finger", 200);


        map_skill("force", "mystforce");
        map_skill("sword", "divine-mystsword");
        map_skill("parry", "mystsword");
        map_skill("dodge", "mysterrier");
        map_skill("move", "mysterrier");
        map_skill("finger", "chuanyun-zhi");
        prepare_skill("finger", "chuanyun-zhi");


        create_family("步玄派", 2, "前辈");
        set("title",HIC"步玄派"+ HIY "前任"+HIW"掌派弟子"NOR);
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

//     carry_object("/d/qiankun/obj/weapon/fengquanjian")->wield();

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
                say("据说晚月庄可以召唤神物了，也不知道本派什么时候才有这样的神物护佑。\n");
        }
        else if (random(2) >0 )
        {
                command("walkby " + ob->query("id"));
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
        if( (int)ob->query_skill("sword",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"剑术修为还不够精纯，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩子，历经千辛万苦，你还是找到这里来了！");
                command("say 现在武当少林如日中天，能否扛起本派复兴的大旗就全看你的了！");
                command("say 为师传你一套步玄派不传之秘——四式连环，它可以将步玄七诀的意境发挥到及至！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIC"步玄派"+HIG"一剑"+HIW"飞仙客"NOR);
                ob->add("wlshw",-50);
                ob->set("can_link",1);
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

