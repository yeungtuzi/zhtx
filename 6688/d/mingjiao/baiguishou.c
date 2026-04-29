// BaiGuiShou.c
// pal 1997.05.11

#include <ansi.h>

inherit NPC;

void create()
{
    set_name("白龟寿", ({ "bai guishou", "bai", "guishou", }));
	set("long",
        "他是一位两鬓斑白的老者，身穿一件白布长袍。\n"
        "他脸上总是浮现出可亲的微笑，但有时又透出一丝狡谲。\n"
	);

    	set("title","明教" HIB "玄武坛" NOR "坛主");

	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 56);
	set("shen_type", 1);
	set("str", 20);
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
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	create_family("明教", 4, "玄武坛坛主");

	setup();

        carry_object(__DIR__"obj/baipao")->wear();
}
