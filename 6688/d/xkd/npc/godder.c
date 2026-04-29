#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("仙尘", ({ "xian chen", "godder" }));
        set("nickname", HIC"无招胜有招"NOR);
        set("long", 
"他是华山派晚辈弟子中的后起之秀，幼年时师从剑宗掌门封不平修习狂风快剑，\n"
"已是武林中一等一的高手，后经武林异士晓风残月的指点，不惧千难万险，寻访\n"
"到了华山派前辈风清扬，终于修习到了传说中的独孤九剑，从而剑行天下，笑傲\n"
"江湖。据说他的剑法实已不在传说中的独孤求败之下，只是生不逢时，遇上了华\n"
"山派气宗剑宗的大火并。劫难过后，他一生致力于将华山气宗和剑宗合而为一，\n"
"无奈势单力薄，说服不了各派名宿，终于饮恨郁郁而终。\n");

        set("gender", "男性");
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
        set_skill("huashan-jianfa", 220);
        set_skill("huashan-neigong", 200);
        set_skill("huashan-shenfa", 200);
        set_skill("hunyuan-zhang", 200);
        set_skill("junzi-sword",200);
        set_skill("literate",300);
        set_skill("move", 200);
        set_skill("blade", 200);
        set_skill("spear", 200);
        set_skill("throwing", 200);
        set_skill("strike", 200);
        set_skill("whip", 200);
        set_skill("parry", 200);
        set_skill("poyu-quan", 200);
        set_skill("purple", 220);
        set_skill("sword", 220);
        set_skill("taiji-jian", 200);
        set_skill("taiji-quan", 200);
        set_skill("taiji-shengong", 250);
        set_skill("taoism", 250);
        set_skill("tiyunzong", 200);
        set_skill("wind-sword", 200);
        set_skill("yanshuangfei", 200);
        set_skill("yunv-sword", 200);
        set_skill("zixia-shengong", 200);
        set_skill("zong-jue", 300);


        map_skill("force", "taiji-shengong");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("sword", "dugu-jiujian");
        map_skill("dodge", "tiyunzong");
        map_skill("move", "yanshuangfei");
        map_skill("parry", "taiji-quan");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派剑宗", 18, "副掌门");
        set("title",HIG "华山派" NOR + HIY "独孤"+HIR"剑圣" NOR);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );        


        set("inquiry", ([
                "道全": 
"哎~~~~~他是我以前的主人，据说现在当了天神，忙的不得了，你有问题可以去找他哦。\n",
                "晓风残月": 
"那是大天神啊!你问他干什么，记着，千万不要和他讨价还价！！！\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

//    carry_object("/d/qiankun/obj/weapon/ziwei")->wield();

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
                  +"好啊! 来我们华山派吧，现在皮都厚了，也不害羞了，嘿嘿～～～\n");
        }
        else
        if( random(10) > 8)
        {
                say("岳不群那家伙据说练了辟邪剑法，在看也不过如此。。。\n");
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
                command("say 好徒儿，既然你的功夫已经如此到家，那为师就收下你了！");
                command("say 今后闯荡江湖时一定不能忘记华山派曾经的屈辱历史，希望在你的手上发扬光大！！");
                command("say 本派复兴的使命就交给你了！！");
                command("recruit " + ob->query("id") );
                ob->set("title", HIG"华山派"+HIY"剑"+HIR"狂"NOR);
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

