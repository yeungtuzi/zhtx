
#include <ansi.h>

inherit NPC;

void create()
{
    	set_name("张中", ({ "zhang zhong", "zhang", "zhong", }));
	set("long",
        "他是一位高高瘦瘦的道人，身穿一件白布长袍。\n"
        "\n"
	);


    	set("nickname", "铁冠道人");
	set("gender", "男性");
	set("attitude", "friendly");

    	set("age", 52);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("title", "明教散人"NOR);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 100);
	set("combat_exp", 500000);
	set("score", 5000);

	set_skill("force", 120);
	set_skill("moni-xinfa",120);
	set_skill("dodge", 120);
	set_skill("yueying-wubu",120);
	set_skill("strike", 120);
	set_skill("moni-strike",120);
	set_skill("parry", 120);
	set_skill("literate", 120);

	map_skill("force","moni-xinfa");
	map_skill("dodge","yueying-wubu");
	map_skill("parry","moni-strike");
	map_skill("strike","moni-strike");

	prepare_skill("strike","moni-strike");

	setup();

    	carry_object(__DIR__"obj/baipao")->wear();
}

