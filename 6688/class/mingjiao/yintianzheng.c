// YinTianZheng.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
    set_name("殷天正", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "他是一位身材魁梧的秃老者，身穿一件白色长袍。\n"
        "他长眉胜雪，垂下眼角，鼻子钩曲，犹如鹰嘴。\n"
	);
                                                          
	set("title","明教护教法王" NOR);
	set("nickname",HIW "白眉鹰王" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen",-500000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("kee", 3500);
	set("max_kee", 3500);
	set("gin", 1500);
	set("max_gin", 1500);
	set("force", 3000);
	set("max_force", 3000);
	set("force_factor", 150);
	set("combat_exp", 900000);
	set("score", 1000000);

	set_skill("force", 180);
	set_skill("dodge", 150);
	set_skill("unarmed", 185);
	set_skill("parry", 150);
	set_skill("claw", 185);
	set_skill("literate", 60);
	set_skill("sougu", 150);
	set_skill("shaolin-shenfa",150);
	set_skill("moni-xinfa",180);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("claw", "sougu");
	map_skill("parry", "sougu");

	prepare_skill("claw", "sougu");

	create_family("明教",36,"弟子");
	
	setup();

}

#include "fawang.h"