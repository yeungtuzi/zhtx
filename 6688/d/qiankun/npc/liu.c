// liu.c 刘安禄
 
#include <ansi.h>
 
inherit NPC;
inherit F_MASTER;
 
 

void create()
{
        set_name(HIR"刘安禄"NOR, ({ "liu anlu", "liu"}) );
 
        set("nickname",  HIR "血手刘三" NOR);
        set("title", HIY "封山派叛徒" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
             "他原是淳风武馆的门房。除了馆主柳淳风没有人知道他的出身来历。\n"
            "没想到他暗中偷学到了封山派的武功，刺杀了封山派掌门柳淳风，\n"
             "带着人头投靠了乾坤教，司空晓风表面上对他礼遇有佳，\n"
             "实际上只是想骗得封山剑法的奥秘罢了。\n" 
        );
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("shen",-500000);
        set("str", 80);
        set("con", 20);
        set("int", 50);
        set("dex", 20);
        set("per", 10);
 
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 300);
        set("max_kee", 4000);
        set("max_gin", 2000);
        set("max_sen", 2000);
 
        set("combat_exp", 7000000);
        set("score", 20000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.counterattack" :)
        }) );

 
         set_skill("force", 110);
         set_skill("dodge", 180);
         set_skill("cuff",180);
         set_skill("parry", 180);
         set_skill("sword", 180);
         set_skill("literate", 180);
         set_skill("fonxanforce", 180);
         set_skill("fonxansword", 180);
         set_skill("liuh-ken", 180);
         set_skill("chaos-steps", 180);

         map_skill("cuff", "liuh-ken");
         map_skill("sword", "fonxansword");
         map_skill("force", "fonxanforce");
         map_skill("parry", "fonxansword");
         map_skill("dodge", "chaos-steps");
         prepare_skill("cuff", "liuh-ken");
 
 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
 
         setup();
         carry_object("/class/swordsman/blackthorn")->wield();
         carry_object("/class/swordsman/hat")->wear();
         carry_object("/class/swordsman/boot")->wear();
         carry_object("/class/swordsman/silk_cloth")->wear();
         carry_object("/d/qiankun/obj/dishashield")->wear();
}
 
 
 
void attempt_apprentice(object ob)  
 {       
          if ((string)this_player()->query("family/family_name")=="乾坤教")
          {if (this_player()->query_skill("fonxansword",1)<100)
             { command("say 就你这样的剑法还想拜我为师，再好好练练去吧！");
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
 



