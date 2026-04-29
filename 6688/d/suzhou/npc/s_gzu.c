//s_gzu.c
//by tlang

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(HIM"公主"NOR, ({"gong zhu" }));
//        set("title", HIW"**"NOR);
        set("long",
                "她原来是朝廷的建业公主，嫁给吴应熊，却于新婚之前阉了吴，嫁给小宝。\n"
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
        set("shen_type", -2);
        set("str", 25);
        set("int", 20);
        set("con", 26);
        set("dex", 26);
	set("per", 27);
        set("max_kee", 500);
        set("max_gin", 200);
	set("max_sen", 200);

        set("force", 360);
        set("max_force", 360);
        set("force_factor", 20);
        set("combat_exp", 150000);
        set("score", 10000);
        set("apply/attack",  60);
        set("apply/defense", 36);

        set_skill("force", 50);
        set_skill("unarmed", 60);
        set_skill("sword", 50);
//	set_skill("finger",150);
        set_skill("dodge", 50);
        set_skill("parry", 50);
//        set_skill("fonxansword",100);
//	set_skill("chaos-steps",100);
//	set_skill("fonxanforce",100);
//	set_skill("force","fonxanforce");
//	map_skill("sword","fonxansword");
//	map_skill("dodge","chaos-steps");
      
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
