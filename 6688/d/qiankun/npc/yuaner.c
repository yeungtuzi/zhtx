#include <ansi.h>
 
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
 
void create()
{
        set_name(HIY"媛儿"NOR, ({"yuan er","yuan","er"}));
        set("nickname", HIY"花伴丽人行"NOR);
        set("long", 
        HIG"媛儿是雪蕊的得意弟子，聪明好学，\n媛儿一帆风顺地学完了铁雪山庄的武功，\n在心爱的人及众多好友相继淡出江湖后，她也悄然归隐。\n想不到乾坤教势力如此强大，连她现在都归附了。\n"NOR);
        set("title", HIC "铁雪乖乖女" NOR);
        set("gender", "女性");
        set("age", 18);
        set("rank_info/respect", "乖乖女");
         create_family("乾坤教", 2, "护法");
 
         set("combat_exp",7000000);
 
        set("max_kee", 4000);
        set("max_gin", 2000);
        set("max_sen",2000); 
        set("force", 6000);
        set("max_force", 4000);
        set("force_factor", 300);
        set("attitude", "friendly");
 
        set("per", 30);
        set("cps", 48);
        set("cor", 30);
 

        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("strike", 180);
        set_skill("qimen-bagua", 71);
        set_skill("unarmed", 180);
        set_skill("literate", 201);
 
        set_skill("deisword",180);
        set_skill("meihua-shou",180);
        set_skill("qidaoforce",180);
        set_skill("fall-steps",180);
  
        map_skill("dodge", "fall-steps");
        map_skill("strike","meihua-shou");
        map_skill("move","fall-steps");
        map_skill("force", "qidaoforce");
        map_skill("parry", "deisword");
        map_skill("sword", "deisword");
        
        prepare_skill("strike","meihua-shou");
 
  
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 80);
 
        set("chat_chance_combat", 20);  
        set("chat_msg_combat", ({
                 (: exert_function, "recover" :),
        }) );
 
        setup();
         carry_object("/d/qiankun/obj/msword")->wield();
         carry_object("/d/qiankun/obj/yuanerbelt")->wear();
}
  
 
void die()
{
        object ob;
         if( objectp(ob = query_temp("last_damage_from")) )
        {
                command("chat " + HIR + ob->query("name") + "你这" + RANK_D->query_rude(ob) + "，师父，我对不起你啊！！！\n"NOR);
        }
        ::die();
}
 
int accept_fight(object who)
{
        command("nomatch "+who->query("id"));
        return 0;
}
 
void killed_enemy(object victim)
{
        command("chat 怎么偏偏有这么多不知死活的家伙呀？");
        command("chat " + victim->query("name") + "你这" + RANK_D->query_rude(victim) + "，给本姑娘死去吧！\n"NOR);
}
void attempt_apprentice(object ob)  
{       
          if ((string)this_player()->query("family/family_name")=="乾坤教")
          {if (this_player()->query_skill("fall-steps",1)<100)
             { command("say 你轻功太差，我不收这样的徒弟");
              return;
              }
             else {command("say 好吧，我就收下你了。");
                  command("recruit " + ob->query("id"));
                  }
           } 
          
}
void recruit_apprentice(object ob)
{
         if( ::recruit_apprentice(ob) )
                if((string)ob->query("gender")!="女性")
                 {
                        ob->set("title",BLK "乾坤教" NOR + HIB +"舵主" NOR);
                        return;
                }
                else
                 {
                        ob->set("title",BLK "乾坤教" NOR + HIB +"舵主" NOR);
                        return;
                }
        
}

