//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name(HIR"雅克鲁"NOR, ({ "ya kelu","wushi"}) );
	set("long",RED@LONG
他的鼻子非常得大！你一看就知道他来自维京的国度，
盛传维京国里武士会一种奇异的妖术，可以千里取人
性命，要小心点了。
LONG NOR
	 );

	set("title",RED"西洋武士"NOR);
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
       


	setup();
	set_skill("qiankun-danuoyi", 220);
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
	set("weapon_type","sword");
		
}                          

                             
int killed_enemy(object ob)
{
	command("say 瓦砾故罗四完的多！");
}                 
