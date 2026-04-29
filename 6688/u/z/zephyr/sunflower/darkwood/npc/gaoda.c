//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void check();
void create()
{
	int lvl,t;
	set("level",6);
	set_name("高大", ({ "gao da","gao","da"}) );
	set("long",YEL@LONG
人非其名，高大长得却原来有些瘦小，甚至看上去有些弱不禁
风的样子。但是他长得却十分英俊潇洒，剑眉星目，让你看就
不由自主的喜欢他。他身后背着一个布包裹，看不清楚那是什
么兵器。
LONG NOR
	 );
	set("title",BLK"钻地"NOR"神鼠");
	set("age",21);
	set("percmd", "exert maxsuck");
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("zui-gun", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("staff",t+random(10));
	set_skill("force",t+random(10));
	set_skill("xianyun",t+random(10));
	set_skill("huagong-dafa",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("jin-gang",t+random(10));
	set_skill("perception", t+random(10));


	map_skill("force","huagong-dafa");
	map_skill("parry","zui-gun");
	map_skill("move","xianyun");
	map_skill("dodge","xianyun");
	map_skill("staff","zui-gun");
	map_skill("iron-cloth","jin-gang");

	set("chat_chance",30);
	setup();
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/staff")->wield();
	set("weapon_type","staff");

}                          

                             
int killed_enemy(object ob)
{
	command("say 很久没有动过手了，手都生了。");
}                 
                     
