// b_header.c

inherit NPC;
//inherit F_MASTER;
inherit F_QUEST;
#include "/d/suzhou/npc/biaoju.h"

void create()
{
        set_name("陈剑秋", ({ "master guardman", "guardman", "master" }) );
        set("nickname", "霹雳刀");
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);

        set("rank_info/respect", "陈镖头");

        set("long",@LONG
    陈剑秋在十几年前创立了振远镖局，凭着一手六合刀法在远近
颇有些名头，因此镖局的生意还算可以。
LONG);

        set("combat_exp", 1000000);
        set("score", 20000);
	set("shen_type",1);

        set_skill("cuff", 90);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("blade", 200);
        set_skill("force", 100);
	set_skill("move",160);
        set_skill("literate", 80);
	set_skill("liuhe-dao",160);
	set_skill("luohan-quan",100);
	set_skill("notracesnow",160);
	map_skill("dodge","notracesnow");
	map_skill("move","notracesnow");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	map_skill("cuff","luohan-quan");
	prepare_skill("cuff","luohan-quan");


        set("inquiry", ([
                "name": "在下姓陈，人称霹雳刀",
                "霹雳刀": "江湖上的弟兄看得起在下就这么叫开了，实在是惭愧。",
        ]) );

        setup();
        carry_object("/d/cloud/obj/npc/b_header/moon_blade")->wield();
}

void init()
{
	::init();
	add_action("give_quest","quest");
}



