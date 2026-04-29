//s_zfren.c
//by tlang

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(HIW"甑夫人"NOR, ({"zen furen", "maddam" }));
        set("long",
                "她是甑士隐的夫人。\n"
        );

        set("gender", "女性");
      
        set("attitude", "peaceful");
        
        set("inquiry",([
                "甑士隐"  : (: ask_me :),
        	"zengshiyin" : (: ask_me :),
	]));

        set("age", 51);
        set("shen_type", 0);
        set("str", 20);
        set("int", 24);
        set("con", 20);
        set("dex", 20);
	set("per", 24);
        set("max_kee", 500);
        set("max_gin", 200);
	set("max_sen", 200);

        set("force", 360);
        set("max_force", 360);
        set("force_factor", 20);
        set("combat_exp", 50000);
        set("score", 100);
        set("apply/attack",  6);
        set("apply/defense", 30);

        set_skill("dodge", 10);
        set_skill("parry", 10);
              
	setup();
      
        add_money("silver", 5);
	carry_object("/d/suzhou/npc/obj/skirt2")->wear();
//	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
}

string ask_me()
{
	command("sigh");
	return "你要找他就去书房吧。。。\n";
}
