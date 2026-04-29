// song.c 宋青书

 
#include <ansi.h>
 
inherit NPC;
inherit F_MASTER;
 
 
void consider();
 
void create()
{
        set_name(HIB"宋青书"NOR, ({ "song qingshu", "song"}) );
 
        set("nickname",  HIB "欺师灭祖" NOR);
        set("title", BLK "天下武林之贼子" NOR);
        set("gender", "男性");
        set("age", 20);
        set("long",
             "他是武当首侠宋远桥的儿子宋青书。\n"
            "自从谋害了自己师叔之后，被峨嵋派收留。\n"
             "不久周芷若修习九阴真经走火入魔导致武功尽失，\n"
             "武林中没有他的容身之处，只好投靠乾坤教来避难，\n" 
             "真可谓臭气相投，但他出逃时还偷学了峨嵋派的武功，\n" 
             "所以对于司空晓风来说，多多少少还有点利用价值。\n" 
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
        set("max_sen", 2000);;
 
        set("combat_exp", 7000000);
        set("score", 20000);
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
         
 
 
         set_skill("force", 180);
         set_skill("linji-zhuang", 180);
         set_skill("dodge", 180);
         set_skill("zhutian", 180);
         set_skill("tiangang-zhi", 180);
         set_skill("finger", 180);
         set_skill("jinding-mianzhang",180);
         set_skill("strike",180);
         set_skill("fuliu-jian",180);
         set_skill("sword",180);
         set_skill("throwing",180);
         set_skill("parry", 180);
         set_skill("literate", 180);
         map_skill("force", "linji-zhuang");
         map_skill("dodge", "zhutian");
         map_skill("finger", "tiangang-zhi");
         map_skill("parry", "fuliu-jian");
         map_skill("sword", "fuliu-jian");
         map_skill("strike", "jinding-mianzhang");
         prepare_skill("finger", "tiangang-zhi");
         prepare_skill("strike", "jinding-mianzhang");
 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
 
         setup();
         carry_object("/d/qiankun/obj/dress")->wear();
         carry_object("/d/qiankun/obj/iceboots")->wear();
}
 
 
 
void attempt_apprentice(object ob)  
 {       
          if ((string)this_player()->query("family/family_name")=="乾坤教")
          {if (this_player()->query_skill("fuliu-jian",1)<100)
             { command("say 就你这样的剑法再回去练个百八十年吧！");
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
 

