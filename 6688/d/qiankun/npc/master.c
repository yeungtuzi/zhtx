// master.c 司空晓风
//By Masterall
#include <ansi.h>
inherit NPC;  
inherit "/std/char/qlist.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";
 
void heal();
void consider();
void create()
{
         set_name("司空晓风", ({ "sikong xiaofeng", "sikong" }));
         set("nickname", HIR "乾纲独断，唯我独尊" NOR);
         set("long",
                 "他就是近些年来声名大噪的乾坤教教主司空晓风\n"
                 "他目光犀利，面如冠玉，一副孤傲的表情中透露出了王者之气。\n"
                 "乾坤教最近发展装大了很多，兼备了不少小门派。\n"
                 "他野心勃勃，准备一统武林，称霸天下\n");
        set("title",BLK "乾坤教" NOR + HIB "教主" NOR);
         set("gender", "男性");
         set("age", 50);
         set("attitude", "friendly");
         set("shen_type", -1);
         set("str", 40); 
         set("int", 30);
         set("con", 30);
         set("dex", 30);
         set("cor", 50);
        set("no_get",1);
         set("max_kee", 5000);
         set("max_gin", 3000);
        set("max_sen",3000);
        set("atman", 3000);
        set("max_atman", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
         set("force", 10000);
         set("max_force", 5000);
         set("force_factor", 350);
           set("combat_exp", 10000000);
        set("shen",-10000000);
         set("chat_chance", 100);
         set("chat_msg", ({
                 (: heal :),
         }));
         set("chat_chance_combat", 60);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
    /*     set("chat_msg_combat", ({
                 (: exert_function , "recover" :),
                 (: exert_function , "refresh" :),
                 (: exert_function , "regenerate" :),                
         }));
 */
         set_skill("force", 200);
         set_skill("taohua-force", 200);
        set_skill("move", 200);
         set_skill("dodge", 200);
         set_skill("fall-steps", 200);
        set_skill("claw", 200);
         set_skill("parry", 200);
         set_skill("sword", 200);
         set_skill("fuliu-jian", 200);
          set_skill("fonxansword", 200);  
         set_skill("cuixin-zhang", 200);
         set_skill("strike", 200);
         set_skill("spicyclaw", 200);
         set_skill("literate", 220);
 
         map_skill("force", "taohua-force");
         map_skill("dodge", "fall-steps");
         map_skill("move", "fall-steps");
        map_skill("strike", "cuixin-zhang");
         map_skill("sword", "fuliu-jian");
         map_skill("parry", "fonxansword");
         map_skill("claw", "spicyclaw");

         prepare_skill("claw", "spicyclaw");
         prepare_skill("strike", "cuixin-zhang");
 
         create_family("乾坤教", 1, "教主");
         set("class", "强盗");
 
         setup();                    
         set_temp("apply/armor_vs_force",100);
         set_temp("apply/armor",100);
         carry_object("/d/qiankun/obj/fakexiaolou")->wield();
         carry_object("/d/qiankun/obj/goldencloth")->wear();
}
 
 
void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "乾坤教")
        {
                command("say 我只收本门弟子，"+ RANK_D->query_respect(ob) + "可先拜赵无极或者六位护法。");
                return;
        }
         if ((int)ob->query_skill("taohua-force", 1) < 180) { 
                 command("say 就你这么点微末功夫还想来拜本教主为师？");
                 command("say " + RANK_D->query_respect(ob) +
                         "先回去好好练练内功吧。");
                 return;
         }
         if ((int)ob->query_skill("fall-steps", 1) < 180) { 
                 command("say 就你这么点微末功夫还想来拜本教主为师？");
                 command("say " + RANK_D->query_respect(ob) +
                         "先回去好好练练轻功吧。");
                 return;
         }
         if ((int)ob->query_skill("cuixin-zhang", 1) < 180) { 
                 command("say 就你这么点微末功夫还想来拜本教主为师？");
                 command("say " + RANK_D->query_respect(ob) +
                         "先回去好好练练掌法吧。");
                 return;
         }
         if ((int)ob->query_skill("fuliu-jian", 1) < 180) { 
                 command("say 就你这么点微末功夫还想来拜本教主为师？");
                 command("say " + RANK_D->query_respect(ob) +
                         "先回去好好练练剑法吧。");
                 return;
         }
         if ((int)ob->query_skill("fonxansword", 1) < 180) { 
                 command("say 就你这么点微末功夫还想来拜本教主为师？");
                 command("say " + RANK_D->query_respect(ob) +
                         "先回去好好练练剑法吧。");
                 return;
         }
         if ((int)ob->query_skill("spicyclaw", 1) < 180) { 
                 command("say 就你这么点微末功夫还想来拜本教主为师？");
                 command("say " + RANK_D->query_respect(ob) +
                         "先回去好好练练爪法吧。");
                 return;
         }
         if ((int)ob->query("shen") >-500000) {
                 command("say 既然入我乾坤教必须要心狠手辣，你心地这么良善，早晚要栽在那些所谓的名门正派的手上！");
                 command("say " + RANK_D->query_respect(ob) +
                         "还是多替本教杀点正派人士再来吧！");
                 return;
         }
         if (ob->query_int() < 40) {
                 command("say 本教武功博大精深，集天下之所长。");
                 command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性是半点也马虎不得");
                 command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可
 挖，还是请回吧。");
                 return;
         }
        
         command("chat 哈哈哈哈！！！！");
         command("chat 想不到本教在蒸蒸日上之时，又觅得一文武全才， 所谓的正派人士都给我听好了，你们的末日快来了！！！")
 ;
         command("recruit " + ob->query("id"));
         this_player()->set("class", "强盗");
         if((string)this_player()->query("gender")!="女性")
                 this_player()->set("title",BLK "乾坤教" NOR + HIB +"护法" NOR);
         else
                this_player()->set("title",BLK "乾坤教" NOR + HIB +"护法" NOR);
 }

void init()
{
  add_action("give_quest","quest");
 }
 
      
 
void heal()
{
         object ob=this_object();
 
         if (ob->query("eff_kee") < ob->query("max_kee"))
         {
                 command("exert heal");
                command("enforce 200");
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

void consider()
{
         object *enemy,target;
         enemy = query_enemy() - ({ 0 });
         target = enemy[random(sizeof(enemy))]; 
         
     //    command("perform parry.counterattack " + target->query("id"));
         command("exert tanzhi " + target->query("id"));
}
 

