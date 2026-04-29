//by lzxx

inherit NPC;

void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo"}));
	set("long", @LONG
她是灵鹫宫昊天部首领，她跟随天山童姥多年，出生入死，
大家都称她余婆娑。
LONG);
	set("gender", "女性");
	set("title", "灵鹫宫昊天部首领");
	set("age", 58);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 35);
	set("int", 25);
	set("per", 25);
	set("con", 25);

	set("kee", 800);
	set("max_kee", 800);
	set("gin", 500);
	set("sen", 500);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 50);

	set("combat_exp", 700000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("hand", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	set_skill("zhemei-shou",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "zhemei-shou");

	//prepare_skill("hand", "zhemei-shou");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :)
	}));

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("obj/cloth")->wear();
        add_money("silver",70);
}
