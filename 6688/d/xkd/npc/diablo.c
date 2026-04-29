#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name(HIW"地狱"+HIR"圣火"NOR, ({ "diyu shenghuo", "diablo" }));
        set("nickname", HIC"笨蛋"+HIY"天师"NOR);
        set("long", 
"他是当年武林中影响力最大的一个人物。据说当年的接头楼主庞斑就是第一次\n"
"败在他的手上，他的道行极为高深，已然到了深不可测的程度。原先的茅山派\n"
"弟子在武林中是没有太高的地位的，但他入门之后则不甘于人后，苦练修行，\n"
"但进境总是极为缓慢，后来他无意中得知茅山派上一代之间发生了一次大火并\n"
"，很多高手命丧与此，茅山派因此而势微。他于是决心探索事实的真相，解破\n"
"这个数十年困扰茅山派的谜团，三年后，真相大白于天下，而武林中也诞生了\n"
"一位前无古人后无来者的绝世高手。据说他当时秘密做了一个档案，很多鲜为\n"
"人知的武林密史都记录在其中，你要想打听点什么消息可以先问问他。他道行\n"
"深厚，法力高强。你发现他的双眸金黄，这正是「谷衣心法」修炼到最高境界\n"
"的徵兆。\n");

        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("cor", 100);
        set("int", 100);
        set("spi", 100); 

        set("cps", 100); 
        set("per", 50);
        set("con", 100);
        set("kar", 100);
        set("bln", 100);

        set("kee", 5000);
        set("max_kee", 5000);
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
        set("mana_factor", 150);
        set("combat_exp", 20000000);
        set("score", 200000);

        set("apprentice_available", 3);
        set_skill("literate", 300);
        set_skill("magic", 220);
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 220);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("gouyee", 200);
        set_skill("qingcheng-steps",200);
        set_skill("yueying-wubu",200);
        set_skill("necromancy", 200);
        set_skill("music", 161);
        set_skill("taoism", 250);
        set_skill("taosword", 200);
        set_skill("zang-buddhi", 300);
        set_skill("bolomiduo", 200);
        set_skill("essencemagic", 200);
        set_skill("space", 200);

        map_skill("force", "gouyee");
        map_skill("sword", "taosword");
        map_skill("dodge", "qingcheng-steps");
        map_skill("move", "yueying-wubu");
        map_skill("parry", "taosword");
        map_skill("spells", "necromancy");
        map_skill("magic", "essencemagic");

        create_family("茅山派", 5, "弟子");
        set_temp("manashield",1);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "netherbolt" :),
//                (: cast_spell, "feeblebolt" :),
//                (: cast_spell, "invocation" :),
//                (: exert_function, "recover" :),
//                (: exert_function, "concentrate" :),
        }) );        


        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
                "独研": 
"过去了好久的事了，还提她做什么呢?\n",
                "道全": 
"那是天神啊!你问他干什么?\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

        carry_object("/d/chengdu/npc/obj/darksword")->wield();
        carry_object("/u/m/masterall/magicring")->wear();

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
                  +"好啊! 看到天神道全记得一定躲远点,据说他是个大酒鬼,但酒量比我可差远了....\n");
        }
        else
        if( random(10) > 8)
        {
                say("我遍访天下寻找仙丹妙药,可惜一直一无所获," + RANK_D->query_respect(ob)

                 +"要能帮我找到真的就感激不尽了!\n");
        }
        else if (random(2) >0 )
        {
                command("mm " + ob->query("id"));
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
      if( (int)ob->query_skill("spells",1) < 180 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"咒术修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query_skill("magic",1) < 180 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"法术修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( !(int)ob->query("marks/zhangtianshi_apprentice") ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"既然已经投入我茅山派门下，就一定先要帮助本门派清理了门户再说。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 嗯... 想入我茅山派？太好了....");
                command("say 那为师这就收下你了，以后一定要勤加修炼，光大我茅山派！！");
                command("recruit " + ob->query("id") );
                ob->add("wlshw",-50);
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
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

void die()
{      
        unconcious();
        "/cmds/imm/full"->main(this_object(),"");
        revive();
        command("dd");
        command("say 我现在都是半个神仙了，怎么会死呢？！");
        command("rascal diyu shenghuo");
        command("heihei"); 
        command("pat diyu shenghuo");
        return;
}

