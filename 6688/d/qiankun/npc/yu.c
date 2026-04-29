// yu.c 余苍山

 
#include <ansi.h>
 
inherit NPC;
inherit F_MASTER;
 
 
void consider();
 
void create()
{
        set_name(HIW"余苍山"NOR, ({ "yu cangshan", "yu"}) );
 
        set("nickname",  HIW "辣手摧心" NOR);
        set("title", HIC "青城派名宿" NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
             "他是青城派掌门余沧海嫡亲兄弟，一向淡泊名利。\n"
            "他掌上的功夫了得，是武林的一把好手。\n"
             "自从青城派没落之后，就逐渐被乾坤教吞并。\n"
             "乾坤教不惜重金将他收买，他对外所说的淡泊名利只是一句骗人的鬼话。\n" 
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
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
         
 
 
         set_skill("strike", 180);
         set_skill("sword", 180);
         set_skill("force", 180);
         set_skill("parry", 180);
         set_skill("dodge", 180);
         set_skill("literate", 180);
         set_skill("throwing",180); 
        
         set_skill("qingcheng-steps", 180);
         set_skill("cuixin-zhang", 180);
         set_skill("qingcheng-force", 180);
         set_skill("pine-sword", 180);
    
 
         map_skill("dodge", "qingcheng-steps");
         map_skill("strike", "cuixin-zhang");
         map_skill("force", "qingcheng-force");
         map_skill("sword", "pine-sword");
         map_skill("parry", "pine-sword");
 
         prepare_skill("strike", "cuixin-zhang");
 
 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
 
         setup();
         carry_object("/d/qiankun/obj/taosurcoat")->wear();
}
 
 
 
void attempt_apprentice(object ob)  
 {       
          if ((string)this_player()->query("family/family_name")=="乾坤教")
          {if (this_player()->query_skill("cuixin-zhang",1)<100)
             { command("say 你掌力太弱，还需苦练才行啊！");
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
 

