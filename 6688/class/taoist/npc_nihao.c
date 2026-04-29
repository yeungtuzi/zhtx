// nihao.c 小情圣 

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;


void create()
{
        set_name("小情圣", ({ "xiao qingsheng", "qingsheng", "nihao" }));
        set("nickname", "寂寞真人");
        set("long", 
"他是茅山派第六代弟子。\n"
"他少年时孤苦伶仃，经历坎坷。后由茅山掌门林忌收留后，深得林忌喜爱，将\n"
"武功尽数相授。\n"
"他相貌英俊，风流倜傥，在江湖中结下不少情缘。但终因种种原因，于三十余\n"
"岁斩断情丝，苦心修炼道术，终于青出于蓝而胜于蓝。据说小小年纪法力修行\n"
"竟已在林忌之上，一般人决不敢轻易相惹。\n");

        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 46);
        set("cor", 25);
        set("int", 31);
        set("spi", 30); 

        set("cps", 30); 
        set("per", 30);
        set("con", 30);
        set("kar", 10);

        set("kee", 800);
        set("max_kee", 800);
        set("gin", 500);
        set("max_gin", 500);
        set("sen", 680);
        set("max_sen", 680);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 112);
        set("atman",2000);
        set("max_atman", 1000);
        set("mana", 3900);
        set("max_mana", 1950);
        set("mana_factor", 41);
        set("combat_exp", 900000);
        set("score", 200000);

	set("apprentice_available", 3);
        set_skill("literate", 155);
        set_skill("magic", 100);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 32);
        set_skill("sword", 51);
        set_skill("parry", 150);
        set_skill("dodge", 151);
        set_skill("gouyee", 150);
        set_skill("qingcheng-steps",131);
        set_skill("necromancy", 150);
        set_skill("music", 21);
        set_skill("qimen-bagua", 40);
        set_skill("taoism", 78);
        set_skill("taosword", 150);

        map_skill("force", "gouyee");
        map_skill("sword", "taosword");
        map_skill("dodge", "qingcheng-steps");
        map_skill("parry", "taosword");
        map_skill("spells", "necromancy");

        create_family("茅山派", 6, "弟子");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
                (: exert_function, "recover" :),
                (: exert_function, "concentrate" :),
        }) );        


        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
                "独研": 
"过去了好久的事了，还提她做什么呢?\n",
                "道可道": 
"那是天神啊!你问他干什么?\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

        carry_object(__DIR__"nihao_sword")->wield();
        carry_object(__DIR__"nihao_scarf")->wear();
        carry_object("/obj/cloth")->wear();

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
                  +"好啊! 天气凉了有没有多穿件衣服啊?\n");
        }
        else
        if( random(10) > 8)
        {
                say("法力总要有种仙丹吃了能涨才好啊," + RANK_D->query_respect(ob)

                 +"说是不是呢?\n");
        }
        else if (random(2) >0 )
        {
                command("hi " + ob->query("id"));
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
        if( (string)ob->query("gender") != "男性" )
                command("say 本门规定不便收女徒，得罪了。");
        else {
                command("say 嗯... 想入我茅山派？太好了....");
                command("recruit " + ob->query("id") );
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

