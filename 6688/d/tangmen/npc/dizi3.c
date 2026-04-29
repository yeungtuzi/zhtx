// dizi3.c
#include <ansi.h>
inherit NPC;

#include <random_name.h>
void create()
{
	string name;

        	name = get_rndname();
	set_name(name, ({ "di zi", "dizi" }));
	set("title", HIR "唐门" NOR + GRN "六代弟子" NOR);
        	set("gender", "男性");
        	set("age", 14);
        	set("attitude", "peaceful");
        	set("shen_type", -1);

	set("str", 15 + random(16));
	set("cps", 15 + random(16));
	set("int", 15 + random(16));
	set("cor", 15 + random(16));
	set("con", 15 + random(16));
	set("spi", 15 + random(16));
	set("per", 15 + random(16));
	set("kar", 15 + random(16));
                                        
	set("kee",300);
        	set("max_kee", 300);
	set("gin",200);
        	set("max_gin", 200);
	set("sen",200);
	set("max_sen", 200);
	set("atman", 100);
	set("max_atman", 100);
	set("mana", 100);
	set("max_mana", 100);

        	set("force", 300);
        	set("max_force", 300);
        	set("force_factor", 10);
	set("combat_exp", 3000);
        	set("score", 100);
                                               
	set_skill("force", 30);
	set_skill("sword", 30);
	set_skill("throwing", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	set_skill("move", 30);                            
	set_skill("strike", 30);
	set_skill("literate", 30);
	set_skill("dugong", 30);

	set_skill("tangmen-xinfa", 30);
	set_skill("tangshi-jian", 30);
	set_skill("mantian-huayu", 30);
	set_skill("taxue-wuhen", 30);
	set_skill("tangmen-duzhang",30);

	map_skill("dodge", "taxue-wuhen");
	map_skill("move", "taxue-wuhen");
	map_skill("force", "tangmen-xinfa");
	map_skill("sword", "tangshi-jian");
	map_skill("parry", "tangshi-jian");   
	map_skill("strike", "tangmen-duzhang");
	map_skill("throwing", "mantian-huayu");

	prepare_skill("strike","tangmen-duzhang");

	create_family("唐门", 6, "弟子");
         	setup();
        	carry_object("/obj/weapon/gangjian")->wield();
	carry_object("/obj/cloth/cloth")->wear();
}
