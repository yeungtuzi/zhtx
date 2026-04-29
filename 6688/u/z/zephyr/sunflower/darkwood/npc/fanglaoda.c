//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);
	set_name("方老大", ({ "fang laoda","fang","chen"}) );
	set("long",HIW@LONG
方老大身宽体胖，脸上始终是挂着乐呵呵的表情。他走起路来摇摇摆摆，滑稽可笑。
可是你仔细看去时，发现他两只小眼睛里射出的光芒动人心魄，偶尔甚至闪过一丝丝
的蓝色光芒，显然他内功造诣已经达到凡人无可企及的地步。这时候他看上去心情不
错，也许你能向他问问路？
LONG NOR
	 );
	set("title",BLK"暗夜"HIW"灵猫"NOR);
	set("nickname",HIG"乐呵呵"NOR);
	set("age",60);
	set("percmd",random(100)>50 ? "exert powerup":"conjure shade sense");

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("essencemagic", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("staff",t+random(10));
	set_skill("force",t+random(10));
	set_skill("notracesnow",t+random(10));
	set_skill("zixia-shengong",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("jin-gang",t+random(10));
	set_skill("cloudstaff",t+random(10));
	set_skill("perception", t+random(10));



	map_skill("force","zixia-shengong");
	map_skill("parry","cloudstaff");
	map_skill("dodge","notracesnow");
	map_skill("move","notracesnow");
	map_skill("staff","cloudstaff");
	map_skill("iron-cloth","jin-gang");
	map_skill("magic","essencemagic");

	set("chat_chance",3);
	setup();

	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/staff")->wield();
	set("weapon_type","staff");

}                          

                             
int killed_enemy(object ob)
{
	command("snicker");
}                 
