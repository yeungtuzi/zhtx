
#include <ansi.h>

inherit NPC;

void create()
{
    set_name("李天垣", ({ "li tianyuan", "li", "tianyuan", }));
	set("long",
        "他是一位看起来很慈祥的老者，身穿一件白布长袍。\n"
        "他是白眉鹰王殷天正的师弟。一双眼睛总是笑眯眯的，但不知为什么，他的下属\n"
        "对他畏如蛇蝎。\n"
    );


    	set("nickname", "慈眉善目");
	set("gender", "男性");
	set("attitude", "friendly");
	
	set("age", 66);
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
	map_skill("dodge", "yueying-wubu");
	map_skill("throwing", "mantian-huayu");
	map_skill("parry", "moni-strike");
	map_skill("strike", "moni-strike");

	prepare_skill("strike", "moni-strike");

    	set("title","明教""天市堂堂主");

	setup();

    	carry_object(__DIR__"obj/baipao")->wear();
}

