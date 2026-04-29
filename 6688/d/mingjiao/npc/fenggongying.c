
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("封弓影", ({ "feng gongying", "feng", "gongying", }));
	set("long",
        "他是一个阴郁的瘦子，身穿一件白布长袍。\n"
        "他脸上阴沉沉的，看来心胸必不开阔。\n"
	);

    	set("title","明教" HIB "神蛇坛" NOR "坛主");

	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 47);
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
	set_skill("parry", 70);

	map_skill("force", "moni-xinfa");
	map_skill("dodge", "taxue-wuhen");
	map_skill("parry", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");

	setup();

        carry_object(__DIR__"obj/baipao")->wear();
}

