#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;


void create()
{
    set_name("唐洋", ({ "tang yang", "tang", "yang", }));
	set("long",
        "他是一位面色阴沉的中年男子，传闻他原是唐门弟子。\n"
        "他工于心计，在毒水暗器方面的造诣为教中第一。\n"
	);

	set("title","明教"HIB"洪水旗"NOR"掌旗使");
	set("gender", "男性");
	set("attitude", "friendly");
	
	set("age", 46);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("moni-xinfa", 85);
	set_skill("dodge", 85);
	set_skill("yueying-wubu", 85);
	set_skill("throwing", 95);
	set_skill("mantian-huayu", 95);
	set_skill("parry", 85);
	set_skill("strike",85);
	set_skill("moni-strike",85);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "taxue-wuhen");
	map_skill("throwing", "mantian-huayu");
	map_skill("parry", "moni-strike");
	map_skill("strike", "moni-strike");

	prepare_skill("strike", "moni-strike");

    	create_family("明教", 37, "弟子");

	setup();

    	carry_object(__DIR__"obj/zhiai")->wear();
	carry_object(__DIR__"obj/dujili")->wield();
}

#include "qizhu.h"
