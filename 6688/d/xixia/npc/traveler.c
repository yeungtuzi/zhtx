#include <ansi.h>

inherit NPC;

void create()
{
	set_name(YEL"游客"NOR, ({ "you ke", "ke" }));
	set("long", @LONG
一个四处闲逛的游客。
LONG);
	set("attitude", "peaceful");

	set("max_kee", 500);
	set("max_gin", 220);
	set("wimpy", 50);
	set("max_sen", 220);
	set("force", 10);
	set("max_force", 10);
	set("force_factor", 0);

	set("combat_exp", 5000);
	set("score", 3);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :),
	}));

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	setup();
 	carry_object("obj/cloth")->wear();
	add_money("silver", 10+random(10));
}
