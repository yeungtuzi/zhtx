#include <ansi.h>

inherit NPC;

string ask_dzxy();

void create()
{
        set_name("慕容复", ({ "murong fu", "murong", "fu"}));
        set("nickname", HIR"南慕容"NOR);
        set("age", 31);
        set("gender", "男性");
        set("rank_info/respect", "慕容公子");
        set("title", "姑苏慕容");
        set("long", @LONG
慕容复是现慕容世家的唯一传人，乃大燕之王孙后代，“以彼之道，还施彼
身”，斗转星移之绝技响彻武林，与丐帮帮主乔峰并称「北乔峰，南慕容」。
慕容复一生为复兴大燕而辗转奔波，只是复国之事谈何容易，至今一无所获。
他双眉斜飞，冷峭高傲，实乃人中龙凤。
LONG);
        set("attitude", "peaceful");

        set("str", 28);
        set("dex", 30);
        set("per", 30);
        set("int", 35);
        set("con", 30);
        set("cor", 30);
        set("cps", 30);
        set("elo", 30);

        set("max_kee", 3000);
        set("max_sen", 900);
        set("max_gin", 900);
        set("max_force", 3000);
        set("force", 6000);
        set("force_factor", 150);

        set("combat_exp", 2500000);
        set("shen_type", -1);
        set("shen", 30000);

        set("inquiry", ([
               "斗转星移": (: ask_dzxy :),
        ]));

        set_temp("apply/armor", 60);
        set_temp("apply/damage", 70);
        set_temp("apply/armor_vs_force", 60);

        set_skill("dodge", 200);
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("hand", 200);
        set_skill("force", 200);
        set_skill("literate", 190);
        set_skill("qi", 170);
        set_skill("music", 120);
        set_skill("sword", 200);

        set_skill("taohua-force", 200);
        set_skill("yuxiao-jian", 200);
        set_skill("lanhua-shou", 200);
        set_skill("fall-steps", 200);
        set_skill("douzhuanxingyi", 200);

        map_skill("hand", "lanhua-shou");
        map_skill("force", "taohua-force");
        map_skill("dodge", "fall-steps");
        map_skill("sword", "yuxiao-jian");
        map_skill("parry", "douzhuanxingyi");
        
        prepare_skill("hand", "lanhua-shou");

        setup();

        carry_object(__DIR__"obj/longsword")->wield();
        carry_object(__DIR__"obj/murong_cloth")->wear();
}
void init()
{
        add_action("do_accept", "accept");
}

string ask_dzxy()
{
        object me = this_player();

     if( me->query("family/family_name") != "逍遥派")
     return "你非逍遥派门下弟子，和我素无瓜葛，问这是如何谈起！";

     if( me->query("skill_mark/douzhuanxingyi")  )
     {       
     return "我不是跟你解说过斗转星移其中秘诀了么？怎么还问！";                      
     }       
     command("heihei "+me->query("id"));
     command("nod "+me->query("id"));
     command("pat "+me->query("id"));
     command("say 既然阁下想学我慕容家独门武功斗转星移，得接我三招不死，你想试试(accept test)？\n");
                me->set_temp("ask_dzxy",1);
}

int do_accept(string arg)
{
        object me = this_player();
                    
                if ( me->query_temp("ask_dzxy",1) ) 
           {
                set("force_factor",250);                
                say("\n慕容复点了点头，说道：很好，这是第一招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say("慕容复叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                        return 1;
                }
                say("\n慕容复说道：这是第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say("慕容复「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
                        return 1;
                }
                say("\n慕容复说道：第三招来了....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say("慕容复叹道：可惜，难道我慕容家的绝学竟无传人....\n");
                        return 1;
                }
                say(HIC"\n慕容复哈哈大笑，说道：阁下武功有如此造诣，我慕容家的绝学后继有人了！\n\n"NOR);
                tell_object(me, HIC"慕容复便将“以彼之道，还施彼身”的斗转星移绝技一一传授于你。\n\n"NOR);
                me->improve_skill("douzhuanxingyi", 10);
                set("force_factor",150);     
                me->delete_temp("ask_dzxy");
                me->set("skill_mark/douzhuanxingyi",1);
                return 1;
           }
           return 0;
}



