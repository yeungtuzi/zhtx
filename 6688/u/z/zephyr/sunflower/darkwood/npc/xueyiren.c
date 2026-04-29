//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",4);
	set_name("薛衣人", ({ "xue yiren","xue"}) );
	set("long",HIG@LONG
他身材清瘦，手握着腰间的剑柄，手指长且有力
显是用剑的高手。
LONG NOR
	 );
	set("title",HIG"薛家庄"NOR"庄主");
	set("nickname",RED"血衣人"NOR);
	set("age", 43);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set("percmd", "exert powerup" );
	set_skill("force", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("sword",t+random(10));
	set_skill("huntian-qigong",t+random(10));
	set_skill("snowstep",t+random(10));
	set_skill("fumo-jian",t+random(10));
	set_skill("perception",t+random(10));


	map_skill("force","huntian-qigong");
	map_skill("dodge","snowstep");
	map_skill("move","snowstep");
	map_skill("sword","fumo-jian");
	map_skill("parry","fumo-jian");


	setup();
	set("per",50);
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	set("weapon_type","sword");
		
}                          

                             
int killed_enemy(object ob)
{
	command("hmm");
}                 

