// ChengChaoFeng.c
// pal 1997.05.11

#include <ansi.h>

inherit NPC;

void create()
{
    set_name("常金鹏", ({ "chang jinpeng", "chang", "jinpeng", }));
	set("long",
        "他是一位体健如牛的大汉，身穿一件白布长袍。\n"
        "他脸上手上的肌肉凹凹凸凸，盘根错节，看来武功修为不浅。\n"
	);

    	set("title","明教" HIR "朱雀坛" NOR "坛主");

	set("gender", "男性");
	set("attitude", "friendly");


	set("age", 45);
	set("shen_type", 1);
	set("str", 100);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 450);
	set("max_gin", 300);
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("finger", 68);
	set_skill("parry", 70);
	set_skill("sword", 80);


    	create_family("明教", 4, "青龙坛坛主");

	setup();

        carry_object(__DIR__"obj/baipao")->wear();
}

