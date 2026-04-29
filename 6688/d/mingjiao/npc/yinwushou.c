#include <ansi.h>

inherit NPC;

void create()
{
    	set_name("殷无寿", ({ "yin wushou", "yin", "wushou", }));
	set("long",
        "他是一位老者，身穿一件白布长袍。\n"
        "他是白眉鹰王殷天正的仆从。整天愁眉苦脸的，一副短命横死相。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");

    	set("age", 57);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("combat_exp", 100000);
	set("score", 5000);

	set("force_factor", 40);

	set("title", HIM"寿比秋蝉"NOR);
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
	map_skill("dodge", "yueying-wubu");
	map_skill("throwing", "mantian-huayu");
	map_skill("parry", "moni-strike");
	map_skill("strike", "moni-strike");

	prepare_skill("strike", "moni-strike");

	setup();

    	carry_object(__DIR__"obj/baipao")->wear();
}

