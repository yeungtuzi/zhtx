//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",4);
	set_name("庞飞", ({ "pang fei","pang"}) );
	set("long",HIG@LONG
他身材高大，站在那里仿佛是一尊金刚，不怒自威，让人不敢逼视。
庞飞出道以来以一身铁布衫金刚不坏的功夫横行武林，威震一时。后
来因为误伤一名好友的性命，郁郁寡欢，不再好勇斗胜。
LONG NOR
	 );
	set("title",CYN"金钟罩铁布衫"NOR);
	set("nickname",YEL"怒目金刚"NOR);
	set("age", 56);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("celestial", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("jin-gang",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("force",t+random(10));
	set_skill("hammer",t+random(10));
	set_skill("mo-chui-jue",t+random(10));
	set_skill("mo-shan-jue",t+random(10));
	set_skill("perception",t+random(10));

	map_skill("force","celestial");
	map_skill("hammer","mo-chui-jue");
	map_skill("parry","mo-chui-jue");
	map_skill("dodge","mo-shan-jue");
	map_skill("move","mo-shan-jue");
	map_skill("iron-cloth","jin-gang");

	set("chat_chance",3);
	setup();
	
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/hammer")->wield();
		
	set("weapon_type","hammer");
}                          

int killed_enemy(object ob)
{
	command("heng");
}                 
                     
