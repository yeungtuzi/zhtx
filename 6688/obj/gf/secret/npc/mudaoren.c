#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
//void ask_luxf();
//void ask_ximen();
void ask_weaponor();
int allow();
int talk_time=random(20)+30;
object me=this_player();

string *msg=({
YEL"木道人闭目半晌，仿佛在回忆很久远之前的往事。\n"NOR,
YEL"良久，木道人睁开眼睛道：“没想到天下还有人知道这本书。”\n"NOR,
YEL"“纵横天下兵器谱乃一得道之人所著，记载着天下几柄神兵利器的资料”\n"NOR,
YEL"“此人自得道之后就再不问世事，天下没有几个人知道他的事情。”\n"NOR,
YEL"“他对我曾经有救命之恩，我本不该轻易相信你，透露他的行踪。”\n"NOR,
YEL"“但既然是孙老先生指点你来此询问，想来你也定非为恶之人。”\n"NOR,
YEL"说到这里，木道人怔了一会...\n"NOR,
YEL"..............\n"NOR,
YEL".................\n"NOR,
YEL"........................\n"NOR,
CYN"你大气都不敢出，生怕打乱了他的思索...\n"NOR,
YEL"良久，木道人叹了口气，仿佛在努力忘掉一些往事\n"NOR,
YEL"木道人缓缓道：好吧，我告诉你他的去处。\n"NOR,
CYN"木道人道：三年前他去了天山寻找一柄兵器，算来应该已经回来了。\n"NOR,
CYN"木道人道：远在天边，近在眼前，他就在此地。你去寻他吧。\n"NOR,
});
void talk(object who, int stage);


void create()
{
        set_name("木道人", ({ "mudaoren" }) );

        set("gender", "男性");
        set("age", 63);
        set("long",
                
"木道人是青城宿老,自从比剑败于林远图后,便不知所踪,想不到今天居然在这里出现.\n");

        set("attitude", "peaceful");
       
        set("str", 15);
        set("int", 29);
        set("cps", 24);
        set("cor", 25);
                set("shen_type",-1);

       
        set("force", 8000);
        set("max_force", 5000);
        set("force_factor", 300);
        set("max_kee", 4000);
        set("max_gin", 500);
        set("max_sen", 500);
                set("count",1);

        set("combat_exp", 10000000);
        

/*        set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
                (: perform_action , "sword.chan" :),              
                (: perform_action , "sword.sanjue" :)
        }) );
*/
        set_skill("strike", 200);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 180);
       
        set_skill("qingcheng-steps", 200);
        set_skill("cuixin-zhang", 200);
        set_skill("qingcheng-force", 200);
        set_skill("pine-sword", 200);
   

        map_skill("dodge", "qingcheng-steps");
        map_skill("strike", "cuixin-zhang");
        map_skill("force", "qingcheng-force");
        map_skill("sword", "pine-sword");
        map_skill("parry", "pine-sword");

        prepare_skill("strike", "cuixin-zhang");
       create_family("青城派", 17, "长老");
        set("inquiry",([
                //"西门吹雪"    : (: ask_ximen :),
                //"陆小凤"    : (: ask_luxf :),
                "纵横兵器谱"    : (: ask_weaponor :),
                "兵器谱"    : "兵器谱？什么兵器谱？我不知道。", 
        ]));

        set_temp("apply/defense", 100);
        setup();

        
        carry_object("/obj/cloth")->wear(); 
        
}

void reset()
{
        delete_temp("learned");
    set("apprentice_available",-1); 
}

void attempt_apprentice(object ob)
{
        call_out("do_recruit", 1, ob);
      
}
void do_recruit(object ob)
{ if((int)ob->query_skill("pine-sword",1)>=130) {
     command( "say 嗯!想不到我在入暮之年还能找到一个可教之人");
     command( "recruit " + ob->query("id") );}
   else command( "say 嗯,你的松风剑法不够坚实，去把功夫学好了再来吧!!");    
}
void init()
{
   add_action("give_quest", "quest");

}

/*void ask_jvshi
{
        object me=this_player();
        message_vision(me,CYN"木道人道：我这老友四海为家，不知道此时身在何处。\n");
        me->set_temp("youling_jvshi",1);
        return;
}
*/

void talk(object who, int stage)
{                       
        tell_object(who, msg[stage]);
        if ( !who || environment(who) != environment() )        return;
        
        if( ++stage < sizeof(msg) ) 
        {
                call_out( "talk", talk_time, who, stage );
                return;
        } 
        remove_call_out("allow");
        call_out("allow", 2);
        return;
}


/*void ask_luxf
{
        int i = random(100);
        object me=this_player();
        if (i>95)
        {
                message_vision(me,RED"木道人缓缓道：此人昔年曾经是老夫的好友，可惜...。\n");
                command("sigh");
        }
        message_vision(me,CYN"木道人闭起双眼，仿佛已经入定，完全不理会你。\n");
        me->set_temp("youling_jvshi",1);
        return;
}

void ask_ximen
{
        int i = random(100);
        object me=this_player();
        if (i>95)
        {
                message_vision(me,RED"木道人缓缓道：此人昔年曾经是老夫的好友，可惜...。\n");
                command("sigh");

        }
        message_vision(me,CYN"木道人闭起双眼，仿佛已经入定，完全不理会你。\n");
        me->set_temp("youling_ximen",1);
        return;
}
*/

void ask_weaponor()
{
        if( query("count")==0 )
        {
        command("?");
                add("count",-1);
            return; 
        }
        if( query("count")<0 )
        {
            return; 
        }
        if ( me->query_temp("weaponor1") && random(70+me->query("kar"))>89 )
        {
                message_vision(CYN"木道人眼中忽然精光四射，仿佛连你的心底也被他看透。\n"NOR,me);
                remove_call_out("talk");
                call_out("talk",talk_time,me,0);    
                add("count",-1);
        }
        return;
}

int allow()
{
        me->set_temp("weaponor2",1);
        if (wizardp(me)) tell_object(me,"you have access to weaponor now\n");
        return 1;
}
