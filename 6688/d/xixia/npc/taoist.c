#include <ansi.h>

inherit NPC;

void create()
{
	set_name("云游道士", ({ "taoist"}) );
	set("gender", "男性");
	set("long", "一个四方云游的老道士。\n");
	set("age", 77);

	set("combat_exp", 1000000);
	set("score", 200000);
	set("class", "taoist");

	set("str", 30);
	set("int", 30);
	set("cor", 20);
	set("cps", 30);
	set("spi", 30);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "drainerbolt" :),
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "invocation" :),
	}) );

	set_skill("literate", 90);
	set_skill("magic", 100);
	set_skill("force", 150);
	set_skill("spells", 150);
	set_skill("cuff", 70);
	set_skill("sword", 130);
	set_skill("parry", 130);
	set_skill("dodge", 100);
	set_skill("move", 100);
	set_skill("move", 100);
	set_skill("qingcheng-steps", 100);

	set_skill("gouyee", 150);
	set_skill("taosword", 150);
	set_skill("taoism", 200);
	set_skill("necromancy", 150);

        map_skill("force", "gouyee");
	map_skill("spells", "necromancy");
	map_skill("sword", "taosword");
	map_skill("parry", "taosword");
	map_skill("dodge", "qingcheng-steps");
	map_skill("move", "qingcheng-steps");

	setup();

	carry_object(__DIR__"obj/longsword")->wield();
	carry_object("obj/cloth")->wear();

	set("max_kee",2000);
	set("eff_kee",2000);
	set("kee",2000);
        set("eff_sen",800);
        set("sen",800);
        set("max_sen",800);
        set("eff_gin",2000);
	set("max_gin",2000);
	set("gin",2000);

	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 50);

	set("atman", 1400);
	set("max_atman", 1400);

	set("mana", 4000);
	set("max_mana", 2000);
	set("mana_factor", 57);
	set_temp("manashield",1);	
}
