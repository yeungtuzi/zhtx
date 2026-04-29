// chen.c 陈玄风

 
#include <ansi.h>
 
inherit NPC;
inherit F_MASTER;
 
 
void consider();
 
void create()
{
        set_name(HIC"陈玄风"NOR, ({ "chen xuanfeng", "chen"}) );
 
        set("nickname",  RED "铜尸" NOR);
        set("title", GRN "桃花岛逆徒" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
             "他是黄药师的大弟子，是桃花岛四大弟子\n"
            "“陈、梅、曲、陆”中的陈玄风，武功最高的\n"
             "自从他和梅超风窃得九阴真经以后，就隐迹江湖\n"
             "想不到他居然躲在这里。\n" 
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
         
 
 
         set_skill("force", 110);
         set_skill("music", 180);
         set_skill("dodge", 180);
         set_skill("strike", 180);
         set_skill("hand",180);
         set_skill("parry", 180);
         set_skill("sword", 180);
         set_skill("literate", 180);
         set_skill("taohua-force", 180);
         set_skill("baguabu", 180);
         set_skill("luoying-zhang",180);
         set_skill("lanhua-shou", 180);
         set_skill("yuxiao-jian", 180);
         set_skill("qimen-bagua", 180);
 
         map_skill("force", "taohua-force");
         map_skill("dodge", "baguabu");
         map_skill("hand", "lanhua-shou");
         map_skill("strike","luoying-zhang"); 
         map_skill("parry", "yuxiao-jian");
         map_skill("sword", "yuxiao-jian");
         prepare_skill("hand","lanhua-shou");
         prepare_skill("strike", "luoying-zhang");

 
 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
 
         setup();
         carry_object("/d/qiankun/obj/skeletonnecklace")->wear();
}
 
 
 
void attempt_apprentice(object ob)  
 {       
          if ((string)this_player()->query("family/family_name")=="乾坤教")
          {if (this_player()->query_skill("taohua-force",1)<100)
             { command("say 你功力太差，我不收这样的徒弟");
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
 
void consider()
{
         object *enemy,target;
         enemy = query_enemy() - ({ 0 });
         target = enemy[random(sizeof(enemy))]; 
         
         command("exert tanzhi " + target->query("id"));
}

