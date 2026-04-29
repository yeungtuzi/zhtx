#include <ansi.h>

inherit NPC;

void create()
{
	set_name("宗赞"NOR, ({ "zon zan", "zon" }));
	set("age", 24);
	set("title", "土蕃王子");
	set("gender", "男性");
	set("long", @LONG
他浓眉大眼，身材魁梧。
LONG);
	set("attitude", "peaceful");

	set("str", 36);
	set("per", 20);
	set("cor", 30);
	set("cps", 12);
	set("lea", 23);

	set("max_kee", 2400);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 40);
	set("combat_exp", 200000);

	set("bellicosity", 100);
	set("shen_type", -1);

	set_temp("apply/attack", 40);
	set_temp("apply/armor", 50);

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("bolomiduo", 80);
	set_skill("dodge", 90);
	set_skill("move", 85);
	set_skill("parry", 100);

	map_skill("force", "bolomiduo");

	setup();

	carry_object(__DIR__"obj/hongpao")->wear();
}
