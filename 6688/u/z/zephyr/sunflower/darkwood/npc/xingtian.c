//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name("刑天", ({ "xing tian","xing","tian"}) );
	set("long",BLU@LONG
刑天江湖从未闻其名，乃是一名隐士。
他正在低着头想着什么事情，见你走了过来，一抬头，
一双眼睛明亮之极，眼珠黑得像漆，精光四射。
LONG NOR
	 );
	set("title","隐士");
	set("age", 53);	

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;
	set("percmd", "perform sword.counterattack" );

	set_skill("cuff", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("sword", t+random(10));
	set_skill("force", t+random(10));

	set_skill("fonxanforce", t+random(10));
	set_skill("fonxansword", t+random(10));
	set_skill("liuh-ken", t+random(10));
	set_skill("chaos-steps", t+random(10));

	map_skill("cuff", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("force", "fonxanforce");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");
	map_skill("move", "chaos-steps");
    prepare_skill("cuff", "liuh-ken");


	setup();
	
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	set("weapon_type","sword");
		
}                          

                             
int killed_enemy(object ob)
{
	command("say 多年没动过手啦！");
	command("sigh");
}                 
                     
