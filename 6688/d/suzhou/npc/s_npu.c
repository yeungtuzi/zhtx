//s_npu.c
//by tlang

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(HIC"女仆"NOR, ({"nv pu", "ren" }));
        set("title", HIW"回头一笑百媚生"NOR);
        set("long",
                "她是甑家唯一的女仆，眼角斜飞，眉目含情。\n"
        );

        set("gender", "女性");
        set("rank_info/respect", "美女");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "贾雨村"  : (: ask_me :),
        	"jiayucun" : (: ask_me :),
	]));

        set("age", 21);
        set("shen_type", -1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
	set("per", 24);
        set("max_kee", 500);
        set("max_gin", 200);
	set("max_sen", 200);

        set("force", 360);
        set("max_force", 360);
        set("force_factor", 20);
        set("combat_exp", 5000);
        set("score", 100);
        set("apply/attack",  6);
        set("apply/defense", 30);

        set_skill("dodge", 10);
        set_skill("parry", 10);
              
	setup();
      
        add_money("silver", 1);
	carry_object("/d/suzhou/npc/obj/skirt")->wear();
//	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
}

string ask_me()
{
	command("shy");
	return "他现在还好吗？\n";
}
