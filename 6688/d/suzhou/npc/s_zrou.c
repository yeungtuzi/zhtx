//s_zrou.c
//by tlang

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name(HIW"曾柔"NOR, ({"zeng rou", "zeng" }));
//        set("title", HIW"**"NOR);
        set("long",
                "她是小宝在王屋山下靠赌博赢得芳心的女子，很温柔的。\n"
        );

        set("gender", "女性");
        set("rank_info/respect", "美女");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "韦小宝"  : (: ask_me :),
        	"小宝" : (: ask_me :),
		"xiaobao" : (: ask_me :),
	]));

        set("age", 21);
        set("shen_type", 0);
        set("str", 20);
        set("int", 30);
        set("con", 26);
        set("dex", 26);
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
        set_skill("sword", 150);
//	set_skill("finger",150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
//      set_skill("nianhua-zhi",100);
	set_skill("xiaoyaoyou",100);
//	map_skill("finger","nianhua-zhi");
//	map_skill("dodge","xiaoyaoyou");
      
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
