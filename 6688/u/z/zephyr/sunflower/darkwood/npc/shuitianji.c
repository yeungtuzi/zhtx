//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void use_poison();
void check();

void create()
{
	int lvl,t;
	set("level",4);
	set("percmd", random(100)>50 ? "exert chillgaze" : "perform dodge.ensnare" );

	set_name("水天姬", ({ "shui tianji","shui"}) );
	set("long",HIG@LONG
水天姬说话行事有点放浪形骸，不拘小节，出手亦是凶狠毒辣。
江湖中听到她的名头，莫不感到一丝寒意。
LONG NOR
	 );
	set("gender", "女性" );
	set("title","女魔头");
	set("age",21);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("finger", t+random(10));
	set_skill("force", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("literate", t+random(10));
	set_skill("perception", t+random(10));
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

	setup();
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: check() :),
		(: use_poison :),
		(: consider :),
	}) );
	set("per",100);

	carry_object("/obj/cloth/cloth")->wear();
	carry_object("obj/weapon/whip")->wield();
	set("weapon_type","whip");
}                          

                             
int killed_enemy(object ob)
{
	command("heng");
}                 
void check()
{
		if ( random(100) > 50 ) 
			command("exert chillgaze");
		else
			command("perform dodge.ensnare");
	
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
		ob->apply_condition("rose_poison", 20);
}

