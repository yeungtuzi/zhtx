// lu.c 陆得财

 
#include <ansi.h>
 
inherit NPC;
inherit F_MASTER;
 
 
void consider();
 
void create()
{
        set_name(HIY"陆得财"NOR, ({ "lu decai", "lu"}) );
 
        set("nickname",  BLK "黑水伏蛟" NOR);
        set("title", MAG "花紫会龙头老大" NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
             "他是原来花紫会的龙头老大。\n"
            "花紫会原本就是一个小帮派，在江湖上势力不大。\n"
             "乾坤教崛起之后，花紫会成为第一个吞并对象。\n"
             "从全帮兄弟的身家性命着想，陆得财只好委曲求全，在乾坤教教了给人当了小弟。\n" 
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
         
 
 
         set_skill("force", 180);
         set_skill("dodge", 180);
         set_skill("claw", 180);
         set_skill("parry", 180);
         set_skill("sword", 180);
         set_skill("literate", 180);
         set_skill("perception", 80);
         set_skill("begging", 100);
         set_skill("stealing", 100);
         set_skill("spicyclaw", 180);
         set_skill("serpentforce", 180);
         map_skill("claw", "spicyclaw"); 
         map_skill("force", "serpentforce");
         map_skill("parry", "spicyclaw");
         prepare_skill("claw", "spicyclaw");
 
 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
 
         setup();
         carry_object("/d/qiankun/obj/macloth")->wear();
         carry_object("/d/qiankun/obj/souhunshou")->wear();
}
 
 
 
void attempt_apprentice(object ob)  
 {       
          if ((string)this_player()->query("family/family_name")=="乾坤教")
          {if (this_player()->query_skill("spicyclaw",1)<100)
             { command("say 就你这点微末功夫，还需苦练才行啊！");
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
 


