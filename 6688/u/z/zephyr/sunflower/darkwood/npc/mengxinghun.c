//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",4);
	set_name("孟星魂", ({ "meng xinghun","meng"}) );
	set("long",GRN@LONG
孟星魂是一个有名的杀手。他善于使剑，名动江湖。但他已
厌倦了杀人、厌倦了流血、厌倦了这种永远见不到阳光的生
活。他本想和心爱的女人小蝶隐居再不做杀手的职业，但他
能逃脱快活门的追杀，能逃脱杀手王高老大的组织，却逃不
脱高老大养育他的恩情。
他低着头，不知道在想着什么
LONG NOR
	 );
	set("title",BLU"杀手组织"NOR"刺客");
	set("nickname",MAG"流星蝴蝶剑"NOR);
	set("age", 22);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;
	set_skill("xuantie-sword", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("sword",t+random(10));
	set_skill("force",t+random(10));
	set_skill("huntian-qigong",t+random(10));
	set_skill("baguabu",t+random(10));
	set_skill("spells",t+random(10));
	set_skill("perception",t+random(10));

	map_skill("force","huntian-qigong");
	map_skill("sword","xuantie-sword");
	map_skill("parry","xuantie-sword");
	map_skill("dodge","baguabu");
	map_skill("move","baguabu");

	set("chat_chance",3);
	setup();
	
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	set("weapon_type","sword");
		
}                          

                             
int killed_enemy(object ob)
{
	command("say 为什么一定要逼我？");
}                 
                     
