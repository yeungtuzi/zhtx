//shangguanren.c
//by masterall
 
#include <ansi.h>
inherit "/u/z/zephyr/revengenpc.c";
string kill_passenger(object who);
void heal();
 
 
void create()
{
     set_name("上官仞",({"shangguan ren","ren"}));
     set("long",@LONG
 他就是乾坤教的创教元勋上官仞，
 后来得罪了教主司空晓风，被贬到这里来看守藏经阁。
 但他仍对司空晓风忠心耿耿，今年来藏经阁一本武林秘笈都没有失窃，反而多了不少。
LONG
     );
        set("title", BLK"乾坤教"NOR+HIB"长老"NOR);
        set("nickname",  HIR "擅入者死！" NOR);
        set("gender","男性");
        set("age", 53);
        set("str", 30);
        set("con", 30);
        set("cor",37);
        set("int", 57);
        set("per", 29);
        set("con",59);
        set("cps",29);
 
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 180);
        set("max_kee", 4000);
        set("max_gin", 2000);
        set("max_sen", 2000);
        set("combat_exp", 8000000);
        set("shen",-1000000);
        set("shen_type",-1);

         set_skill("force", 180);
         set_skill("taohua-force", 180);
        set_skill("move", 180);
         set_skill("dodge", 180);
         set_skill("fall-steps", 180);
        set_skill("claw", 180);
         set_skill("parry", 180);
         set_skill("sword", 180);
         set_skill("fuliu-jian", 180);
          set_skill("fonxansword", 180);  
         set_skill("cuixin-zhang", 180);
         set_skill("strike", 180);
         set_skill("spicyclaw", 180);
         set_skill("literate", 180);
 
         map_skill("force", "taohua-force");
         map_skill("dodge", "fall-steps");
         map_skill("move", "fall-steps");
        map_skill("strike", "cuixin-zhang");
         map_skill("parry", "fuliu-jian");
         map_skill("sword", "fonxansword");
         map_skill("claw", "spicyclaw");

         prepare_skill("claw", "spicyclaw");
         prepare_skill("strike", "cuixin-zhang");
 
         create_family("乾坤教", 2, "长老");
         set("class", "强盗");
       
       setup();

        add_money("gold", 25);
        carry_object("/d/qiankun/obj/helmet")->wear();


}

void init()
{
        add_action("do_gogo", "go");
}
 
int do_gogo(string arg)
{
        object me;
        me = this_player();
        if( arg == "northup" )
        {
                if( this_player()->query_skill("taohua-force",1)<100 ) 
                {
        command("heng"); 
        command("say 藏经阁难本教机关重地，任何人不得擅入！");
        write("这个方向的路被上官仞挡住了 。\n");
        return 1;
                }
                else
                        return 0;               
        }
        return 0;
}

void attempt_apprentice(object ob)
{
         command("sigh"); 
         command("say 我年纪大了，阁下还是另选高明吧。");
         return;
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
