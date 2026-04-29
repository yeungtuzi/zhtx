// GaoShanWang.c
// pal 1997.05.11

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("高山王", ({ "gao shanwang", "gao", "shanwang", }));
	set("long",
        "他是一位身宽体胖的老者，身穿一件白布长袍。\n"
        "他正笑嘻嘻地看着你，好象对你颇有好感。\n"
	);

    	set("title","明教" HIC "白虎坛" NOR "坛主");

	set("gender", "男性");
	set("attitude", "friendly");

    	set("age", 51);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_kee", 450);
	set("max_gin", 300);
	set("foce", 600);
	set("max_force", 600);
	set("force_factor", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("moni-xinfa", 70);
	set_skill("dodge", 70);
	set_skill("taxue-wuhen", 70);
	set_skill("hand", 68);
	set_skill("zhemei-shou", 68);
	set_skill("parry", 70);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "taxue-wuhen");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");

	setup();

        carry_object(__DIR__"obj/baipao")->wear();
}

