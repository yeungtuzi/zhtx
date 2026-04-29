//s_fyi.c
//by tlang

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(HIW"方怡"NOR, ({"fang yi","fang" }));
//        set("title", HIW"**"NOR);
        set("long",
                "她是一个既温柔又泼辣的女子，不过还是挺让人喜欢的。\n"
        );

        set("gender", "女性");
        set("rank_info/respect", "美女");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "韦小宝"  : (: ask_me :),
        	"小宝" : (: ask_me :),
		"xiaobao" : (: ask_me :),
	]));

        set("age", 22);
        set("shen_type", 0);
        set("str", 20);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
	set("per", 28);
        set("max_kee", 500);
        set("max_gin", 200);
	set("max_sen", 200);

        set("force", 360);
        set("max_force", 360);
        set("force_factor", 20);
        set("combat_exp", 500000);
        set("score", 100000);
        set("apply/attack",  60);
        set("apply/defense", 36);

        set_skill("force", 150);
        set_skill("unarmed", 60);
        set_skill("sword", 150);
//	set_skill("finger",150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("fonxansword",50);
	set_skill("chaos-steps",50);
	set_skill("fonxanforce",50);
	map_skill("force","fonxanforce");
	map_skill("sword","fonxansword");
	map_skill("dodge","chaos-steps");
      
	setup();
      
        add_money("gold", 1);
	carry_object("/d/suzhou/npc/obj/skirt2")->wear();
	carry_object("/d/suzhou/npc/obj/gangjian")->wield();
}

string ask_me()
{
	command("blush");
	return "他正是我的夫君啊！\n";
}
