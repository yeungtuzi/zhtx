// master.c
// modified by thir in zh 97/7/10
#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

string ask_chushi();
void create()
{
        set_name("柳淳风", ({ "master swordsman", "swordsman", "master" }) );
        set("nickname", "风雨双侠");
        set("gender", "男性" );
        set("class", "swordsman");
        set("age", 44);
        set("str", 27);
        set("cor", 30);
        set("cps", 27);
        set("int", 24);
        set("no_get",1);

        set("max_force", 1500);
        set("force", 2500);
        set("force_factor", 30);

        set("rank_info/respect", "柳馆主");

        set("long",
                "柳淳风是个相当高大的中年儒生，若不是从他腰间挂著的「玄苏剑」你\n"
                "大概猜不到眼前这个温文儒雅的中年人竟是家大武馆的馆主。\n");

        create_family("封山剑派", 13, "掌门人");

        set("combat_exp", 1000000);
        set("score", 200000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.counterattack" :)
        }) );

        set_skill("cuff", 140);
        set_skill("parry", 200);
        set_skill("dodge", 180);
        set_skill("sword", 180);
        set_skill("force", 160);
        set_skill("literate", 60);

        set_skill("fonxanforce", 160);
        set_skill("fonxansword", 180);
        set_skill("liuh-ken", 140);
        set_skill("chaos-steps", 180);
//      set_skill("spider-array", 85);

        prepare_skill("cuff", "liuh-ken");
        map_skill("cuff", "liuh-ken");
        map_skill("sword", "fonxansword");
        map_skill("force", "fonxanforce");
        map_skill("parry", "fonxansword");
        map_skill("dodge", "chaos-steps");

        set("inquiry", ([
                "淳风武馆" : "淳风武馆是先父所创，在下辱承其名，虽忝掌封山门户，不敢忘了先人遗志。",
                "先人遗志" : "先父临终之时将这武馆交到在下手中，需得好好照看。",
                "刘安禄" : "刘兄弟在寒舍管事已经五年了，过去之事不须再提。",
                "name": "你既然知道我是柳馆主，怎麽不知道我是柳淳风？",
                "here": "这里便是淳风武馆。",
                //"出师": (:ask_chushi:),
        ]) );

        setup();
        carry_object(__DIR__"blackthorn")->wield();
        carry_object(__DIR__"hat")->wear();
        carry_object(__DIR__"silk_cloth")->wear();
        carry_object(__DIR__"boot")->wear();
}
/*
string quest_file(string tag) {
        return( "/quest/qlist0");
}
*/

void init()
{
        ::init();
        add_action("give_quest", "quest");
}

// if not allow quest ,then return 0
//int valid_quest() {
//      return 1;
//}


// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

void attempt_apprentice(object ob)
{
        /*command("say 现在武馆凋敝不堪，我已决意退隐，从此不理武林世事，这位" + RANK_D->query_respect(ob) + "请回。\n");
        command("say 不过，若" + RANK_D->query_respect(ob) + "只是想习武健身，老夫倒可以指点一二。\n");
        return;*/
        if( ((int)ob->query("cor") < 20) 
        ||      ((int)ob->query("cps") < 20)) {
                command("say 学剑之人必须胆大心细，依我看" + RANK_D->query_respect(ob) + "的资质似乎不宜？");
                return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}

int recognize_apprentice(object me)
{
        return 1;
}
        
int accept_learn(object me, string skill)
{
      /*if( me->query("family/family_name") == "封山剑派" && me->query("mud_age") > 86400*4 && me->query("faith") > 500 )
                return 1;
                
        if( me->query("age") > 15 )
        {
                command("say " + RANK_D->query_respect(me) + "可惜已过习武的大好年纪，强自学习，有害无益，还是请回吧。\n");  
                return 0;
        }
        
        if( me->query_skill(skill,1) > 50 )
        {
                command("say 老夫传你这点功夫，虽不能在江湖上扬名立万，强身健体却已绰绰有余，" + RANK_D->query_respect(me) + "请回。\n");      
                return 0;
        }
*/
        if( SKILL_D(skill)->query_faith_req(me->query_skill(skill,1)) ) {
                command("say " + to_chinese(skill) + "乃本门绝学，老夫可不敢擅自传授。\n");
                return 0;
        }       
        return 1;
}       

int can_chushi(object me,object dizi)
{
        mapping skills;
        string *sk_key;
        int i;
                
        skills = me->query_skills();
        if( !mapp(skills) ) return 1;
        sk_key = keys(skills);
        i = sizeof(sk_key);
        if( !i ) return 1;
        
        while( i-- )
        {
                if( dizi->query_skill(sk_key[i],1) < skills[sk_key[i]] )
                        return 0;
        }       
        return 1;       
}       

string ask_chushi()
{
        object me = this_player();
        
        if( me->query("family/family_name") != "封山剑派" )     
                return RANK_D->query_respect(me) + "非本门弟子，不知此话怎讲？\n";
        if( me->query("betrayer") )
                return RANK_D->query_respect(me) + "既已背叛师门，又何提此事！\n";
      if( !can_chushi(this_object(),me) && me->query("mud_age") > 86400*4)
                return "老夫这点微末功夫你都没学完，提什么出师！\n";
                
        command("sigh");
        command("say 老夫不才，忝掌封山剑派数十载，未能光大本门，却落得门派凋敝。");
        say("柳淳风面上满是萧索之意\n");        
        me->set("chushi_mark/封山派",1);
      me->delete("family");
        return "老夫不能再贻误后人了，你去吧。";                
}       

