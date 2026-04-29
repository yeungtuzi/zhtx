//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",1);
	set_name("独孤求败", ({ "dugu qiubai","dugu"}) );
	set("long",MAG@LONG
独孤求败剑法天下无双。二十岁执刚猛利剑与天下英雄争锋，三十岁使软剑紫薇
已鲜有敌手，到四十岁掌中钝剑已天下无敌。其后行走江湖欲寻一敌手而不可得，
埋剑隐居，再不问江湖之事。
LONG NOR
	 );
	set("title",CYN"葵花宫"HIM"副宫主");
	set("nickname",HIR"剑魔"NOR);
	set("age",100);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("taiji-shengong", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("sword",t+random(10));
	set_skill("force",t+random(10));
	set_skill("dugu-jiujian",t+random(10));
	set_skill("taiji-jian",t+random(10));
	set_skill("bat-steps",t+random(10));
	set_skill("perception", t+random(10));

	map_skill("force","taiji-shengong");
	map_skill("sword","dugu-jiujian");
	map_skill("dodge","bat-steps");
	map_skill("parry","taiji-jian");

	set("chat_chance",3);

	setup();
	set("per",50);

	carry_object("obj/cloth/cloth")->wear();
	carry_object("obj/weapon/sword")->wield();
	set("weapon_type","sword");
}                          

                             
int killed_enemy(object ob)
{
	command("poetsigh");
}                 
                     
#include "/u/z/zephyr/sunflower/npc/boss.h"
