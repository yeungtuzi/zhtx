//s_ake.c
//by tlang

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(MAG"阿珂"NOR, ({"a ke", "ke" }));
//        set("title", HIW"**"NOR);
        set("long",
                "她是陈圆圆的亲生女儿，容貌就不必细说了。\n"
        );

        set("gender", "女性");
        set("rank_info/respect", "美女");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "韦小宝"  : (: ask_me :),
        	"小宝" : (: ask_me :),
		"xiaobao" : (: ask_me :),
	]));

        set("age", 20);
        set("shen_type", 0);
        set("str", 20);
        set("int", 30);
        set("con", 25);
        set("dex", 25);
	set("per", 30);
        set("max_kee", 500);
        set("max_gin", 200);
        set("force", 360);
        set("max_force", 360);
        set("force_factor", 20);
        set("combat_exp", 200000);
        set("score", 100000);
        set("apply/attack",  60);
        set("apply/defense", 36);

        set_skill("force", 60);
        set_skill("unarmed", 60);
        set_skill("sword", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
      
        setup();
      
        add_money("gold", 1);
	carry_object("/d/suzhou/npc/obj/skirt")->wear();
	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
}

string ask_me()
{
	command("blush");
	return "他正是我的夫君啊！\n";
}

