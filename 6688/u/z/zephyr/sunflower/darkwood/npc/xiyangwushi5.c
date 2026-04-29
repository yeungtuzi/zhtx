//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name(HIG"忽忽图"NOR, ({ "huhu tu","wushi"}) );
	set("long",GRN@LONG
他看上去好像是个僧人，却又和中土的僧人很不一样，
虽然也剃了头发，但是头顶却烫着一个怪异的图案，不
知道代表着什么。
LONG NOR
	 );

	set("title",GRN"西洋武士"NOR);
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
	map_skill("move", "xianyun");
	map_skill("dodge", "xianyun");
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
	command("say 叽里咕噜哇哩哇啦！");
}                 
