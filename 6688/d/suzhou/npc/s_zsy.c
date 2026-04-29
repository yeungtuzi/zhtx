//s_zsy.c
//by tlang

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIC"甑士隐"NOR, ({"zeng shiyin", "zeng" }));
        set("title", HIW"爱学习"NOR);
        set("long",
                "有名的大儒甑士隐。\n"
        );

        set("gender", "男性");
        set("rank_info/respect", "大儒");

        set("attitude", "peaceful");
        
        set("age", 56);
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
	set("per", 27);
        set("max_kee", 500);
        set("max_gin", 200);
	set("max_sen", 200);

        set("force", 360);
        set("max_force", 360);
        set("force_factor", 20);
        set("combat_exp", 300000);
        set("score", 100000);
        set("apply/attack",  60);
        set("apply/defense", 36);

        set_skill("force", 60);
        set_skill("unarmed", 60);
    	set_skill("dodge", 150);
        set_skill("parry", 150);
             
	setup();
      
        add_money("gold", 1);
	carry_object("/d/suzhou/npc/obj/baishan")->wear();
//	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
}

