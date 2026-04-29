// master.c
#include <ansi.h>
inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

void consider();

string ask_sword();

void create()
{
        set_name("骆云舟", ({ "master scholar", "master", "scholar" }) );

        set("gender", "男性");
        set("age", 32);
        set("long",
                "骆云舟生於京城有名的武林世家，他的本名是骆建炎，但是因为生性喜爱\n"
                "四处游荡，遂自号「云舟」，四处游山玩水，结交豪杰异人。数年前继承\n"
                "其父骆易而成为步玄派的新任掌门，但是喜爱飘泊的个性仍然不改，令门\n"
                "中耆宿头痛不已。\n" );

        set("class", "scholar");
        set("attitude", "peaceful");
        create_family("步玄派", 7, "掌门人");

        set("str", 30);
        set("cor", 30);
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("no_get",1);

        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 200);
        set("max_gin",3000);
        set("max_kee",5000);
        set("max_sen",5000);
        set("combat_exp", 5000000);
        set("score", 2000000);
        set("inquiry", ([
                "步玄神剑": (: ask_sword :),
        ]));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.mirror" :),
                //(: exert_function, "recover" :),
                (: perform_action, "dodge.hasten" :),
        }) );

        set_skill("finger", 80);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("parry", 160);
        set_skill("dodge", 200);
        set_skill("move", 100);
        set_skill("literate", 220);
        set_skill("perception", 80);
        set_skill("music", 100);
        set_skill("mystforce", 200);
        set_skill("mysterrier", 200);
        set_skill("mystsword", 200);
        set_skill("chuanyun-zhi", 200);
        set_skill("finger", 200);

        map_skill("force", "mystforce");
        map_skill("dodge", "mysterrier");
        map_skill("move", "mysterrier");
        map_skill("sword", "mystsword");
        map_skill("finger", "chuanyun-zhi");
        prepare_skill("finger", "chuanyun-zhi");

        setup();
        set_temp("apply/astral_vision",1);
        set_temp("apply/defense",100);
        carry_object(__DIR__"windspring")->wield();
        carry_object("/obj/cloth")->wear();
}

int accept_learn(object me, string skill)
{
        if( (int)me->query_skill(skill, 1) > (int)me->query_skill("literate", 
1) )
        {
                tell_object(me,"骆云舟对你专务杂学似乎不太满意，你最好多花一些功夫在读
书上。\n");
                return notify_fail("骆云舟对你专务杂学似乎不太满意，你最好多花一些功夫
在读书上。\n");
        }
        return ::accept_learn(me, skill);
}

void attempt_apprentice(object me)
{
        command("hmm");
        command("say " + RANK_D->query_respect(me) + "有心成为我步玄派的弟子，
那再好不过了。\n");
        command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
        ob->set("class", "scholar");
        return ::recruit_apprentice(ob);
}

void init()
{
   add_action("give_quest","quest");
}

/*void init()
{
        ::init();
        add_action("give_quest", "quest");
}
*/
// if not allow quest ,then return 0
//int valid_quest() {
//      return 1;
//}


// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什
么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真
笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

//不和纯的NPC对手战斗
//自动charge玩家对手                    
int chat()
{
        object *victims;
        int flag,i;
        
        if( !is_fighting() ) return ::chat();
        
        clean_up_enemy();
        flag = 0; 
        victims=query_enemy();
        i = sizeof(victims);
        while(i--)
        {
                if( userp(victims[i]) )
                {
                        charge_ob(victims[i]);
                        return ::chat();
                }
        }                             
        this_object()->remove_all_killer();
        return ::chat();
}

string ask_sword()
{
        object me = this_player();
     if( me->query("family/family_name") != "步玄派")
     return "阁下与本派素无来往，问这个是何用意呢？\n";

     if( me->query_skill("mystsword",1) < 250 )
     return "你还是先好好练习小步玄剑吧！\n";

     if( me->query_skill("mystforce",1) < 250 )
     return "你还是先好好练习步玄心法吧！\n";

     if( me->query_skill("mysterrier",1) < 250 )
     return "你还是先好好练习步玄七诀吧！\n";

     if( me->query("skill_mark/divine-mystsword")  )
     {       
     return "为师不是已经传授了你步玄神剑的要诀了？自己努力加紧修炼吧！";                      
     }
     command("pat "+me->query("id"));
     command("nod "+me->query("id"));
     command("say 既然徒儿你的步玄心法、步玄七诀、小步玄剑都已经日臻化境，\n为师这就将步玄神剑传授于你！！\n");
                call_out("telling_shenjian", 1, 0); 
                me->set_skill("divine-mystsword", 1);
                me->set("skill_mark/divine-mystsword",1);

}

void telling_shenjian(int i)
{
        string *msg = ({
"步玄神剑乃是本派当年镇派绝学，但后来步玄弟子多以轻功见长，\n",
"久而久之，其剑法亦轻盈有余，而威猛不足。为师曾经尝试过将轻盈\n",
"之长补威猛之短，但每遇强敌，总不能得心应手，即便伤敌，亦不能\n",
"命中要害，给其致命一击，往往功亏一篑。痛定思痛之时，为师方悟\n",
"到剑道之真谛，创出了这惊世绝学——步玄神剑。但修炼此剑法损耗\n",
"内力真元极大，不但要求修习者悟性奇高，而且必须得有顽强的意志\n",
"力和扎实的内功作为基础，进一步突破自身的极限。为师这便将此剑\n",
"法要诀传授于你，修习成败与否就看你的造化了！\n",
"\n\n你的「步玄神剑」进步了！
\n",
});
         
        if( i >= sizeof(msg) ){
                this_object()->delete_temp("telling");
                return;
        }
        message_vision(HIG+msg[i]+NOR, this_object());
        call_out("telling_shenjian", 1, i+1);
        return;
}


