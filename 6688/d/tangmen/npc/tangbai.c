//tangbai.c
//written by tang

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void heal();
void create()
{
	set_name("唐白", ({ "tang bai", "bai" }));
        	set("long",
                "他是唐门门主唐云的二儿子。\n"
                "相貌英俊，刚满十六岁，看起来踌躇满志。\n");
	set("title",HIR "唐门" NOR + GRN "二少爷" NOR);
	set("gender", "男性");
        	set("age", 16);
        	set("attitude", "friendly");
        	set("shen_type", -1);

	set("str", 15 + random(16));
	set("cps", 15 + random(16));
	set("int", 15 + random(16));
	set("cor", 15 + random(16));
	set("con", 15 + random(16));
	set("spi", 15 + random(16));
	set("per", 15 + random(16));
	set("kar", 15 + random(16));
                                        
	set("kee",700);
        	set("max_kee", 700);
	set("gin",500);
        	set("max_gin", 500);
	set("sen",500);
	set("max_sen", 500);
	set("atman", 100);
	set("max_atman", 100);
	set("mana", 100);
	set("max_mana", 100);

	set("chat_chance_combat", 100);
        	set("chat_msg_combat", ({
	 	(: perform_action , "throwing.mantian" :)
	        }) );                      
        	set_temp("apply/armor", 50);

        	set("force", 700);
        	set("max_force", 700);
        	set("force_factor", 20);
          	set("combat_exp", 50000);
        	set("score", 10000);

        	set_skill("force", 70);
        	set_skill("tangmen-xinfa", 70);
	set_skill("move", 70);
        	set_skill("dodge", 70);
        	set_skill("taxue-wuhen", 70);
	set_skill("strike", 70);
        	set_skill("tangmen-duzhang", 70);
        	set_skill("parry", 70);
        	set_skill("sword", 70);
        	set_skill("tangshi-jian", 70);
	set_skill("throwing",70);
	set_skill("mantian-huayu",70);
               set_skill("literate", 100);          
	set_skill("dugong",70);

        	map_skill("force", "tangmen-xinfa");
        	map_skill("dodge", "taxue-wuhen");            
	map_skill("move", "taxue-wuhen");
	map_skill("strike", "tangmen-duzhang");
        	map_skill("parry", "tangshi-jian");
        	map_skill("sword", "tangshi-jian"); 
	map_skill("throwing", "mantian-huayu");

        	prepare_skill("strike", "tangmen-duzhang");

        	create_family("唐门", 5, "弟子");
        	set("class", "legend");

        	setup();
        	carry_object("/obj/weapon/gangjian")->wield();
        	carry_object("/d/tangmen/obj/jinyi")->wear();
}

void attempt_apprentice(object ob)
{
	if( (string)this_player()->query("gender")=="男性")
		command("say 我不收弟子，"+ RANK_D->query_respect(ob) + "可先拜我大哥为师。\n");
	if( (string)this_player()->query("gender")=="女性")
		command("say 我不收弟子，"+ RANK_D->query_respect(ob) + "可先拜我大姐为师。\n");
	return;
}

void init()
{
}
