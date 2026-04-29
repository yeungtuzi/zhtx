#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
    set_name("庄铮", ({ "zhuang zheng", "zhuang", "zheng", }));
	set("long",
        "他是一位高大魁伟的中年男子，身穿一件白布长袍。\n"
        "他天生神力，手中的两头狼牙棒有万夫不当之勇，真是一条威风凛凛的汉子。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 42);
	set("shen_type", 1);
        set("str", 100);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	set("combat_exp", 100000);
	set("score", 5000);

	set("title", "明教锐金旗"NOR"掌旗使");

	set_skill("force", 85);
	set_skill("moni-xinfa", 85);
	set_skill("dodge", 85);
	set_skill("yueying-wubu", 85);
	set_skill("strike", 95);
	set_skill("moni-strike", 95);
	set_skill("parry", 85);
	set_skill("staff", 85);
	set_skill("tianshan-zhang", 85);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike", "moni-strike");
	map_skill("parry", "moni-strike");
	map_skill("staff","tianshan-zhang");

	prepare_skill("strike", "moni-strike");

    	create_family("明教", 37, "弟子");

	setup();

    	carry_object(__DIR__"obj/langyabang")->wield();
    	carry_object(__DIR__"obj/yaodai")->wear();
    	carry_object(__DIR__"obj/zhiai")->wear();
}

#include "qizhu.h"
