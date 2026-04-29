#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";


void create()
{
        set_name("余沧海", ({ "yu canghai", "yu", "canghai","master" }) );

        set("gender", "男性");
        set("age", 43);
        set("long",@LONG               
"余沧海是青城派十八代掌门人，松风剑法已经练得登峰造极。\n"
LONG	
        );
        set("attitude", "peaceful");
       
        set("str", 25);
        set("int", 26);
        set("cps", 24);
        set("cor", 25);
	set("shen_type",-1);
	set("no_get",1);
       
        set("force", 1500);
        set("max_force", 1200);
        set("force_factor", 90);

        set("combat_exp", 1500000);
//        set("score", -30000);

        set("chat_chance_combat", 60);
	 set("chat_msg_combat", ({
                (: perform_action , "sword.chan" :),              
                (: perform_action , "sword.sanjue" :)
        }) );
        set_skill("strike", 100);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("throwing",100);
       
        set_skill("qingcheng-steps", 100);
        set_skill("cuixin-zhang", 100);
        set_skill("qingcheng-force", 120);
        set_skill("pine-sword", 140);
   

        map_skill("dodge", "qingcheng-steps");
        map_skill("strike", "cuixin-zhang");
        map_skill("force", "qingcheng-force");
        map_skill("sword", "pine-sword");
        map_skill("parry", "pine-sword");

	prepare_skill("strike", "cuixin-zhang");

        create_family("青城派", 18, "掌门人");

        set_temp("apply/defense", 50);
        setup();
        carry_object(__DIR__"obj/jian")->wield();
        carry_object("/obj/cloth")->wear(); 
        add_money("gold",3);
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
{ if((int)ob->query("combat_exp")>=50000) {
	 command( "say 嗯!入我青城派就得下苦功,把我青城派发扬光大。");
     	 command( "recruit " + ob->query("id") );}
   else command( "say 嗯,你的经验还不够，先去好好练功吧!");	
        }
void init()
{
   add_action("give_quest", "quest");

}

