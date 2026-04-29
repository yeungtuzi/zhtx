//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",4);
	set_name("姬冰雁", ({ "ji bingyan","ji"}) );
	set("long",RED@LONG
在他那张菱角分明的脸上，你看不见丝毫的懒惰、迟钝和犹豫不决，
这大多数人都具有的毛病，在他的身上消失的无影无踪，这个精明
和强锐的化身又怎会不成为人群中的翘楚。
LONG NOR
	 );
	set("title","剑客");
	set("nickname",RED"大漠孤雁"NOR);

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("force", t+random(10));
	set_skill("taiji-shengong", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("taiji-jian", t+random(10));
	set_skill("sword",t+random(10));
	set_skill("pixie-sword", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("perception", t+random(10));


	map_skill("sword","pixie-sword");
	map_skill("force", "taiji-shengong");
	map_skill("parry", "taiji-jian");
	map_skill("dodge", "pixie-sword");
	map_skill("move", "pixie-sword");

	setup();

	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	set("weapon_type","sword");
}                          
                             
int killed_enemy(object ob)
{	object me = this_object();
	command("hmm");
	message_vision(RED"姬冰雁低头看了看手中的剑，血正一滴一滴从剑刃上滑落........\n"NOR,me);
}                 
