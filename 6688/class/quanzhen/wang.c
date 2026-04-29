//wang.c
//made by hacky
//王重阳
#include <ansi.h>
inherit "/u/z/zephyr/revengenpc.c";
inherit F_QUEST;
inherit F_MASTER;
inherit "/feature/challenge";

void heal();

void create()
{
   set_name("王重阳",({"wang chongyang","wang"}));
   set("nickname",HIR"中神通"NOR);
   set("long",@LONG
他就是全真教的开山祖师，武林中号称中神通的王重阳，
他身材消瘦，精神矍铄，飘飘然仿佛神仙中人，
LONG
    );
    set("title",HIB"全真派"NOR+YEL"开山祖师"NOR);
    set("gender","男性");
    set("age",80);
    set("attitude","friendly");
    set("shen_type",1);
    set("str",50);
    set("int",30);
    set("con",30);
    set("dex",30);
    set("no_get",1);

    set("chat_chance_combat",10);
//    set("chat_msg_combat",({
//       (:perform_action,"finger.qiankun-yizhi":),
//   })); 

    set("chat_chance",100);
    set("chat_msg",({
       (:heal:),
    }));
    set("max_kee",5000);
    set("max_gin",5000);
     set("max_force",5000);
     set("force",5000);
    set("force_factor",210);
     set("combat_exp",6000000);

    set_skill("parry",220);
    set_skill("dodge",200);
    set_skill("cuff",180);
    set_skill("force",220);
    set_skill("xiantian-gong",200);
    set_skill("literate",150);
    set_skill("taoism",250);
    set_skill("quanzhen-jian",210);
    set_skill("finger",200);
    set_skill("yiyang-zhi",200);
    set_skill("fx-step",200);
    set_skill("yangxin-quan",200);
    set_skill("kongming-quan",180);
    set_skill("sword",180);

    map_skill("force","xiantian-gong");
    map_skill("dodge","fx-step");
    map_skill("finger","yiyang-zhi");
    map_skill("sword","quanzhen-jian");
    map_skill("parry","yiyang-zhi");
    map_skill("cuff","kongming-quan");

    prepare_skill("finger","yiyang-zhi");

    setup();
    create_family("全真派",1,"开山祖师");
    set("class","taoist");

    carry_object("/d/quanzhen/npc/obj/robe")->wear();
    carry_object("/obj/weapon/changjian");
    
  }
void attempt_apprentice (object ob)
{ 
     int exp;      
     object obj;

   if((string)ob->query("family/family_name")!="全真派")
   {
command("say " + RANK_D->query_respect(ob) + "若想入我重阳宫，可先拜尹志平。\n");  
   return;
    }

   if((int)ob->query("shen")<50000)
   {
    command("say 学武之人，德义为先，希望" + RANK_D->query_respect(ob) + "多做些善事，\n");
   return;
      }
   if((int)ob->query_skill("xiantian-gong",1)<60)
   {
     command("say " + RANK_D->query_respect(ob) + "还应在先天功上多下些功夫!\n");
    return;
    }
   if((int)ob->query("betrayer")>=2)
   {
   command("say 学武之人最忌背信弃义，你多次判师，我怎么能够收你!\n");
   return;
    }
   if((int)ob->query("combat_exp")<200000)
    {
     command("say 你再练几年吧!");
     return;
    }
   
       command("say 好吧，我就收下你吧.\n");
       command("recruit " + ob->query("id"));
      if(ob->query("have_sword")) 
       {
                exp = (int) ob->query("combat_exp");
        if( exp<=150000) {
            ob->set("title",HIB"全真派"NOR+RED"散仙"NOR);
        } else if (exp<=300000) {
            ob->set("title" ,HIB"全真派"NOR+RED"地仙"NOR);
        } else if (exp<=450000) {
            ob->set("title",HIB"全真派"NOR+RED"人仙"NOR);
        } else  {
            ob->set("title",HIB"全真派"NOR+RED"天仙"NOR);
        }
        return;}
      else {
       command("say 我也没有什么好给你的，\n");
       command("say 这里有一吧长剑，我将它刻上你的名字送与你吧,\n");
       command ("say 希望你能用这把剑惩恶扬善.\n");
    
    message_vision("王重阳气沉丹田，指锋急转，抽出自己的佩剑，刻上了你的名字\n",this_player());
    message_vision("王重阳给你一把刻有你名字的长剑\n",this_player());
        obj = new("/d/quanzhen/npc/obj/jian");
        obj->move(this_player());
        ob->set("have_sword",1);
       }
 
        exp = (int) ob->query("combat_exp");
        if( exp<=150000) {
            ob->set("title",HIB"全真派"NOR+RED"散仙"NOR);
        } else if (exp<=300000) {
            ob->set("title" ,HIB"全真派"NOR+RED"地仙"NOR);
        } else if (exp<=450000) {
            ob->set("title",HIB"全真派"NOR+RED"人仙"NOR);
        } else  {
            ob->set("title",HIB"全真派"NOR+RED"天仙"NOR);        
   }
}
void heal()                                             
{                                                       
	object ob=this_player();                        
	                                                
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
	{	command("exert regenerate");            
                                                        
               return;
               }                                         
}                                                       

void init()
{
    add_action("give_quest","quest");
 }
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什-
么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你-
好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

