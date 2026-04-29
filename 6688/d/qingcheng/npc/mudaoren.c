#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;


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

