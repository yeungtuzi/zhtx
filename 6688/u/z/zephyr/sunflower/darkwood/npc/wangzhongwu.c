//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name("王仲武", ({ "wang zhongwu","wang","zhongwu"}) );
	set("long",BLU@LONG
只见此人国字脸庞，两挑斜飞剑眉，一双精光四射的眼睛正四处打量，
让人不敢正视。身后斜背着一口宝刀，刀身看去没什么惊人之处，你
仔细看时，发现刀竟似粘在他身上一般，其实并无绳索之类捆绑着。
此刀必有异处！此时他正四处张望，仿佛正在等待什么人，又像正在
找寻着什么。
LONG NOR
	 );

	set("title",HIW"玄天"YEL"神虎"NOR);
	set("nickname",HIB"啸天"NOR);
	set("age", 35);
	set("percmd","exert powerup");
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("strike", t+random(10));
	set_skill("blade", t+random(10));
	set_skill("force", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("iron-cloth", t+random(10));
	set_skill("jin-gang", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("perception", t+random(10));

	set_skill("celestial", t+random(10));
	set_skill("celestrike", t+random(10));
	set_skill("bat-steps", t+random(10));
	set_skill("shortsong-blade", t+random(10));
	
	map_skill("blade", "shortsong-blade");
	map_skill("iron-cloth", "jin-gang");
	map_skill("parry", "shortsong-blade");
	map_skill("force", "celestial");
	map_skill("strike", "celestrike");
	map_skill("dodge", "bat-steps");
	map_skill("move", "bat-steps");
    prepare_skill("strike", "celestrike");


	setup();
	
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("obj/weapon/blade")->wield();
	set("weapon_type","blade");
		
}                          

                             
int killed_enemy(object ob)
{
	command("disap1");
}                 

