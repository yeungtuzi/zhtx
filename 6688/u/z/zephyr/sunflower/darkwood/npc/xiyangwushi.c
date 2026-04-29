//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name(HIW"乌鲁图"NOR, ({ "wulu tu","wushi"}) );
	set("long",WHT@LONG
他穿的衣服不似中土服饰，是由土色的粗布制成，仿
佛用一张波斯毯裹在身上。最奇怪的是他头上扎着一
块很大的头巾。显然这不是中土人士。
LONG NOR
	 );

	set("title",WHT"西洋武士"NOR);
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
	command("say 兀里术呼斯，雅苏里！！");
}                 
