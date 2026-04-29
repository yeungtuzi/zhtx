//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void use_poison();
void check();

void create()
{
	int lvl,t;
	set("level",2);
	set_name("蓝蔻", ({ "lan kou","lan"}) );
	set("long",CYN@LONG
蓝寇在江湖中名声极好。她生于医学世家，幼年时因机缘巧合拜投在海螺山脚的海若真人
门下，习得一身惊世武功。二十岁开始行走江湖，她生性淡泊，不喜与人争斗，因此甚少
与人动手，可江湖人都知道她几次出手却从未输过，一身武功，天下无人敢小觑。
三年前她应葵花宫宫主之邀，到此做了采月楼楼主。
LONG NOR
	 );

	set("gender", "女性" );
	set("title",CYN"葵花宫"HIC"采月楼"NOR"楼主");
	set("nickname",YEL"冷月飘香"NOR);

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("finger", t+random(10));
	set_skill("sword", t+random(10));
	set_skill("force", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("literate", t+random(10));
	set_skill("perception", t+random(10));
	set_skill("music", t+random(10));
	set_skill("whip", t+random(10));
	set_skill("stormdance", t+random(10));
	set_skill("tenderzhi", t+random(10));
	set_skill("iceforce", t+random(10));
	set_skill("snowwhip", t+random(10));

	map_skill("dodge", "stormdance");
	map_skill("move", "stormdance");
	map_skill("parry", "snowwhip");
	map_skill("finger", "tenderzhi");
	map_skill("force", "iceforce");
	map_skill("whip", "snowwhip");
	prepare_skill("finger", "tenderzhi");
	set("chat_chance",3);

	setup();
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		"蓝寇皱了皱眉头，似乎很不愿意与人动手。\n",
		"蓝寇回首嫣然一笑。\n",
		(: check() :),
		(: use_poison :),
		(: consider :),
	}) );

	set("per",200);
	set("age",23);
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("obj/weapon/whip")->wield();
	set("weapon_type","whip");
}                          

                             
int killed_enemy(object ob)
{
	command("sigh");
}                 

void check()
{
	object *enemys,victim;
	int i;
	enemys = query_enemy();
	i = sizeof(enemys);
	victim = enemys[random(i)];	
	if ( ( victim->query("class") == "bonze" ) || ( victim->query("gender")=="女性" ) ) {
		command("exert chillgaze");
        if ( random(100) > 50 ){
			command("kick " + victim->query("id"));
			command("say 你这个 " + RANK_D->query_rude(victim) + "干吗来打扰本姑娘！");

		}
		else{
			command("inn " + victim->query("id"));
			command("qifu " + victim->query("id"));
		}
	}
	else {
		if ( random(100) > 30 ) 
			command("exert chillgaze");
		else
			command("perform dodge.ensnare");
	}
}

void use_poison()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob->query_condition("rose_poison") ) return;

	tell_object(ob, "你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
		ob->apply_condition("rose_poison", 50);
}

#include "/u/z/zephyr/sunflower/npc/boss.h"
