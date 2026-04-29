// /d/xizang/class/bad/npc/ddang.c

#include <ansi.h>

inherit NPC;

void use_poison();

void create()
{
        set_name("叮当", ({ "ddang", "ding dang", "ding", "dang" }));
	set("title", HIC"追魂客"+NOR);
	set("gender", "女性" );
	set("age", 30);
	set("str", 22);
	set("cor", 30);
	set("cps", 30);
	set("int", 26);
	set("per", 29);
	set("spi", 29);
	set("long", @TEXT
她就是晚月庄的大弟子叮当,人称追魂客,轻功绝佳,出手又快又狠.据说她和黑
店老板小雨点是莫逆之交,经常联手杀人
TEXT
);
	set("combat_exp", 3900000);
	set("attitude", "heroism");
	set_skill("unarmed", 180);
	set_skill("parry", 170);
	set_skill("dodge", 500);
	set_skill("stormdance", 150);
	set_skill("tenderzhi", 150);
	set_skill("whip", 180);
	set_skill("snowwhip", 230);
	set_skill("force", 230);
	set_skill("iceforce", 230);

	map_skill("dodge","stormdance");
	map_skill("unarmed","tenderzhi");
	map_skill("whip", "snowwhip");
	map_skill("parry", "snowwhip");
	map_skill("force", "iceforce");

	set("force",1900);
	set("max_force",1900);
	set("force_factor",77);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: use_poison :),
	}));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/whip")->wield();
//	carry_object(__DIR__"obj/poison")->set_amount(100);
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( ob->query_condition("noname") ) return;

        tell_object(ob, 
"你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("noname", 20);
}
