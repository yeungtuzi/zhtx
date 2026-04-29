
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("颜垣", ({ "yan yuan", "yan", "yuan", }));
	set("long",
        "他是一个矮矮胖胖的汉子，身穿一件白布长袍。\n"
	"走起路来象豚鼠一样，十分滑稽。\n"
	);
	
	set("title", "明教"HIM"厚土旗"NOR"掌旗使");
    	set("age", 48);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 10);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("moni-xinfa", 85);
	set_skill("dodge", 85);
	set_skill("yueying-wubu", 85);
	set_skill("strike", 95);
	set_skill("moni-strike", 95);
	set_skill("parry", 85);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike", "moni-strike");
	map_skill("parry", "moni-strike");

	prepare_skill("strike", "moni-strike");

    	create_family("明教", 37, "弟子");
	setup();

        carry_object(__DIR__"obj/zhanpao1")->wear();
}

#include "qizhu.h"
