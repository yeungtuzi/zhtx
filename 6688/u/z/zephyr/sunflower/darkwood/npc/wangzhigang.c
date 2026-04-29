//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name("汪至罡", ({ "wang zhigang","wang"}) );
	set("long",RED@LONG
瘦削的脸庞上五官十分俊俏，眼光柔和，如若不是腮下长着三寸长的胡须，
让人猛地一看一定会误认为此人是个女子。他身上仿佛并未带什么兵器。
腰间的腰带上中部镶嵌了三刻闪烁着奇异光芒的宝石，一定价值连城。可
是奇怪的是他身上的衣服看上去却非常朴素。
LONG NOR
	 );

	set("title",CYN"苏州"NOR"书生");
	set("nickname",RED"落魄书生"NOR);
	set("age", 23);
	set("percmd","exert powerup");
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("force", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("cuff",t+random(10));
	set_skill("zixia-shengong",t+random(10));
	set_skill("yan-shuangfei",t+random(10));
	set_skill("poyu-quan",t+random(10));
	set_skill("perception",t+random(10));

	map_skill("force","zixia-shengong");
	map_skill("dodge","yan-shuangfei");
	map_skill("move","yan-shuangfei");
	map_skill("cuff","poyu-quan");
	map_skill("parry","poyu-quan");
	prepare_skill("cuff","poyu-quan");

	setup();
	
	carry_object("/obj/cloth/cloth")->wear();
		
}                          

                             
int killed_enemy(object ob)
{
	command("disap1");
}                 

