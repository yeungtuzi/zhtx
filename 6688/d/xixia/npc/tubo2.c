#include <ansi.h>

inherit NPC;

void create()
{
	set_name(YEL"土蕃武士"NOR, ({ "tubo fighter", "fighter" }));
	set("age", 18+random(29));
	set("gender", "男性");
	set("long", @LONG
此人身高六尺有余，异常魁梧，站在你面前，直如铁塔般。
LONG);
	set("attitude", "peaceful");

	set("str", 53);
	set("max_kee", 2400);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 40);
	set("combat_exp", 300000);
	set("shen_type", -1);

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("bolomiduo", 80);
	set_skill("iron-cloth", 120);
	set_skill("dodge", 90);
	set_skill("move", 85);
	set_skill("parry", 100);
	set_skill("staff", 250);

	map_skill("force", "bolomiduo");

	setup();

	carry_object(__DIR__"obj/stick")->wield();
	carry_object("obj/cloth")->wear();
}
