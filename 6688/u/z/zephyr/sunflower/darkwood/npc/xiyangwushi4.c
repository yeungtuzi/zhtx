//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name(HIB"西牟犁"NOR, ({ "xi muli","wushi"}) );
	set("long",BLU@LONG
他兰目金发，看上去非常十分潇洒。穿一袭蓝色衣衫，
腰间束黑色缎带，十分精练的样子。
LONG NOR
	 );

	set("title",BLU"西洋武士"NOR);
	set("age", 23);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("force",t+random(10));
	set_skill("jiuyang-shengong", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("xianyun", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("sword", t+random(10));
	set_skill("shenghuo-shengong",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("qiankun-danuoyi",220);
	map_skill("iron-cloth", "jiuyang-shengong");
	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "xianyun");
	map_skill("move", "xianyun");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "shenghuo-shengong");
	set("chat_chance",3);
	setup();
	set_skill("qiankun-danuoyi", 220);
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
	set("weapon_type","sword");
		
}                          
                             
int killed_enemy(object ob)
{
	command("say 瓦希里哇里乌鲁呼！");
}                 
