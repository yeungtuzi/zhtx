
#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
    set_name("拓跋", ({ "tuo ba","tuo","ba" }));
	set("long",
        "他是一位带发修行的头陀，身穿一件白布长袍。\n"
        "他个子不高，但很结实，看上去颇为纯朴。可是脸上经常浮现出奇怪的笑容，让\n"
        "人有些摸不着头脑。\n"
	);

	set("title","明教" NOR "风字门门主");
	set("level",5);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 22);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 450);
	set("max_gin", 300);
	set("force", 600);
	set("max_force", 600);
	set("forca_factor", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("moni-xinfa", 70);
	set_skill("dodge", 70);
	set_skill("taxue-wuhen", 70);
	set_skill("strike", 68);
	set_skill("moni-strike", 68);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("moni-sword", 70);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike", "moni-strike");
	map_skill("parry", "moni-strike");
	map_skill("sword", "moni-sword");
	prepare_skill("strike", "moni-strike");
	create_family("明教",37,"弟子");

	setup();
	carry_object(__DIR__"obj/mirror")->wear();
	carry_object(__DIR__"obj/miaodao")->wield();
}

#include "menzhu.h"
