#include <ansi.h>

inherit NPC;

void check();

void create()
{
	set_name(MAG"丫鬟"NOR, ({ "maid" }));
	set("long", @LONG
贵妇人的贴身丫鬟。
LONG);
	set("gender", "女性");
	set("age", 16);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 20+random(10));

	set("max_kee", 350);
	set("max_gin", 220);
	set("wimpy", 50);
	set("max_sen", 150);
	set("force", 10);
	set("max_force", 10);
	set("force_factor", 0);

	set("chat_chance", 20);
	set("chat_msg", ({
		(: check :)
	}));

	set("combat_exp", 1200);
	set("score", 3);
	set_skill("force", 10);
	set_skill("unarmed", 30);
	set_skill("move", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);

	setup();
 	carry_object("obj/cloth")->wear();
}

void check()
{
	if (present("lady")) {
		if (random(2) > 0)
			command("say 夫人，天色不晚了，我们回去吧！");
		else	command("follow lady");
	}
	else
		command("say 你看到我们家夫人吗？");
}
