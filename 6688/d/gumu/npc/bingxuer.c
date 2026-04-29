// bing xuer.c 冰雪儿
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("冰雪儿", ({ "bing xuer","tin" }));
        
         set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
        set("long",
                "她是古墓派的使女，小时候在丐帮长大，不知道后来为什么到了古墓派。\n"
                "她看起来十多岁，天生丽质，只是脸色略显白色，象一个不食人间烟火的仙子。\
n");
        set("gender", "女性");
        set("age", 19);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 32);
        set("con", 20);
        set("dex", 30);
        set("per", 50);
        set("max_kee", 1500);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("enforce", 80);
        set("combat_exp", 500000);
        set("score", 20000);
        set_skill("force", 120);
        set_skill("yunu-xinfa", 120);
	set_skill("cuff", 120);
	set_skill("meinu-quan", 120);
        set_skill("dodge", 130);
        set_skill("xianyun", 130);
        set_skill("parry", 120);
        set_skill("whip", 120);
        set_skill("xiangmei-bian", 120);
	set_skill("throwing",120);
	set_skill("zhinv-zhen",120);
        set_skill("literate", 80);

       

        map_skill("force", "yunu-xinfa");
	map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "xiangmei-bian");
        map_skill("whip", "xiangmei-bian");

	prepare_skill("cuff", "meinu-quan");

       

        create_family("古墓派" , 4, "弟子");
        set("class","gumu");
        setup();
        carry_object("/d/shaolin/obj/changbian")->wield();
       	carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
	if((string)ob->query("family/family_name")!="古墓派")
		{
		 command("say " + RANK_D->query_respect(ob) + "若想拜我派需要从入门弟子做起。"); 
                return;
        	}
	 if ((int)ob->query_skill("yunu-xinfa",1) < 30)
		 {
		 command("say " + RANK_D->query_respect(ob) + "玉女心法太低，再回去好好努力吧。"); 
                return;
        	}
        else
          {
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
           }
       
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	        
                	ob->set("title",GRN "古墓派" NOR + YEL +"女使" NOR);
			return;
               

}
void re_rank(object student)
{
	        
                	student->set("title",GRN "古墓派" NOR + YEL +"女使" NOR);
			return;
             
}


void init()
{
        ::init();
        add_action("give_quest","quest");
}	