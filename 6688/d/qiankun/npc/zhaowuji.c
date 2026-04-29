//zhaowuji.c
//by masterall
 
#include <ansi.h>
inherit NPC;
inherit F_QUEST;
inherit F_MASTER;
void heal();
 
 
void create()
{
     set_name("赵无极",({"zhao wuji","zhao"}));
     set("long",@LONG
 他就是乾坤教的掌教弟子赵无极，
 他精明强干，深得教主的信赖，把大大小小的事情都交给了他办，
 虽然武功不是很高，在教中地位却颇高。
LONG
     );
        set("title", BLK"乾坤教"NOR+HIB"总管"NOR);
        set("nickname",  HIW "惟命是从" NOR);
        set("gender","男性");
        set("age", 33);
        set("str", 30);
        set("con", 30);
        set("cor",37);
        set("int", 57);
        set("per", 29);
        set("con",59);
        set("cps",29);
 
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 100);
        set("max_kee", 2000);
        set("max_gin", 1000);
        set("max_sen", 1000);
        set("combat_exp", 2000000);
        set("shen",-100000);
        set("shen_type",-1);

         set_skill("force", 100);
         set_skill("taohua-force", 100);
        set_skill("move", 100);
         set_skill("dodge", 100);
         set_skill("fall-steps", 100);
        set_skill("claw", 100);
         set_skill("parry", 100);
         set_skill("sword", 100);
         set_skill("fuliu-jian", 100);
          set_skill("fonxansword", 100);  
         set_skill("cuixin-zhang", 100);
         set_skill("strike", 100);
         set_skill("spicyclaw", 100);
         set_skill("literate", 100);
      //   set_skill("buddhism", 200);
 
         map_skill("force", "taohua-force");
         map_skill("dodge", "fall-steps");
         map_skill("move", "fall-steps");
        map_skill("strike", "cuixin-zhang");
         map_skill("parry", "fuliu-jian");
         map_skill("sword", "fonxansword");
         map_skill("claw", "spicyclaw");

         prepare_skill("claw", "spicyclaw");
         prepare_skill("strike", "cuixin-zhang");
 
         create_family("乾坤教", 3, "总管");
         set("class", "强盗");
       
       setup();

        add_money("gold", 10);
        carry_object("/d/qiankun/obj/tao")->wear();

}

void attempt_apprentice(object ob)  
{       
        if ((int)ob->query("shen") >0)
        {
                command("say 你们这些正派的人物都给我滚出去，再不走格杀勿论！");
                return;
        }

        if((int)ob->query_skill("taohua-force", 1) < 80 )
        {
                command("say 你的桃花内功火候不够，没有资格进入总舵修习！先去桃花分舵拜师吧。");
                return;
        }
        
        if((int)ob->query_skill("fall-steps", 1) < 80 )
        {
                command("say 你的秋风步法火候不够，没有资格进入总舵修习！先去铁雪山庄分舵拜师吧。");
                return;
        }
        
        if((int)ob->query_skill("cuixin-zhang", 1) < 80 )
        {
                command("say 你的催心掌火候不够，没有资格进入总舵修习！先去青城分舵拜师吧。");
                return;
        }
        
        if((int)ob->query_skill("fuliu-jian", 1) < 80 && ob->query("gender") == "女性")
        {
                command("say 你的回风拂柳剑火候不够，没有资格进入总舵修习！先去峨嵋分舵拜师吧。");
                return;
        }

        if((int)ob->query_skill("spicyclaw", 1) < 80 )
        {
                command("say 你的油流麻香手火候不够，没有资格进入总舵修习！先去花紫分舵拜师吧。");
                return;
        }

        if((int)ob->query_skill("fonxansword", 1) < 80 )
        {
                command("say 你的封山剑法火候不够，没有资格进入总舵修习！先去封山分舵拜师吧。");
                return;
        }        
        
        command("say 阁下既然有心加入我教，那本座就收下你了！");
        command("say 日后要杀尽天下义士，毕生忠于本教！");
        command("say 为教主赴汤蹈火，万死不辞！");
        command("recruit " + ob->query("id"));
}

void heal()                                                
{                                                          
        object ob=this_object();                           
                                                           
        if (ob->query("eff_kee") < ob->query("max_kee"))     
        {                                                  
                command("exert heal");                     
                command("enforce 30");                     
                return;                                    
        }                                                  
                                                            
        if (ob->query("kee") < ob->query("eff_kee"))         
        {                                                  
                command("exert recover");                  
                return;                                    
        }                                                  
                                                            
        if (ob->query("gin") < ob->query("eff_gin"))     
                command("exert regenerate");               
                                                            
        return;                                            
} 
void init()
{
  add_action("give_quest","quest");
 }
 

 
int valid_bribe(object who,int val) {
         message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
         return(0);
}
 
 // called when not finish the task
 int quest_punish(object who) {
         message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任务吧！\n" ,who);
     who->set("quest",0);
     return(0);
}

