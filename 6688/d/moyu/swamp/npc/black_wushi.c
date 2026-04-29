#include <ansi.h>

inherit NPC;
inherit "/ldg/std/rnd_skilld.c";
inherit "/ldg/std/rnd_equipd.c";

#include "random_name.h"

void random_skills();

void create()
{
	set_name(get_rndname(), ({get_rndid(),"wushi","shi"}));
	set("title", BLK"黑衣武士"NOR);
	set("long",
	"这是一个身材高大的江湖人，两臂粗壮，膀阔腰圆，看起来似乎不怀好意。\n"
	);

	set("gender", "男性");
	set("attitude", "aggressive");
	
	set("age", 20+random(30));

	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("int", 25+random(10));
	set("con", 25+random(10));

	set("kee", 1500);
	set("max_kee", 1000+random(1000));
	set("gin", 1000);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 1000+random(1000));
	set("force_factor", 50+random(100));

	set("combat_exp", 1000000+random(2000000));
	set("score", 1);
	set_temp("apply/armor",100+random(100));
	set_temp("apply/damage",30+random(50));
	
        setup();
	random_skills();
	if(random(10)>7) carry_rnd_equip(0,3);
	if(random(10)>7) carry_object("/d/moyu/obj/nineflower");
}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void random_skills()
{
	string rforce_skill,rdodge_skill,*rweapon_skill,weapon_skill_type;
	mapping weapon_skill;
	set_skill("force", 100+random(80));
	set_skill("parry", 100+random(80));
	set_skill("dodge", 100+random(100));
	rforce_skill=rnd_force();
	weapon_skill=rnd_weapon_skill();
	rdodge_skill=rnd_dodge();
	rweapon_skill=keys(weapon_skill);
	weapon_skill_type=weapon_skill[rweapon_skill[0]];
	
	
	set_skill(rdodge_skill,100+random(80));
	set_skill(rweapon_skill[0],100+random(80));
	set_skill(weapon_skill_type,100+random(80));
		
	map_skill("force",rforce_skill);
	map_skill("dodge",rdodge_skill);
	map_skill("move",rdodge_skill);
	map_skill(weapon_skill_type,rweapon_skill[0]);
	map_skill("parry",rweapon_skill[0]);
	
	if(weapon_skill_type=="cuff"||weapon_skill_type=="claw"||weapon_skill_type=="strike")
		prepare_skill(weapon_skill_type,rweapon_skill[0]);
	if(weapon_skill_type=="sword") carry_object("/obj/weapon/longsword")->wield();
	else if(weapon_skill_type=="blade") carry_object("/obj/weapon/gangdao")->wield();
	else if(weapon_skill_type=="staff") carry_object("/obj/weapon/staff")->wield();
	else if(weapon_skill_type=="spear") carry_object("/obj/weapon/yinqiang")->wield();
	else if(weapon_skill_type=="whip") carry_object("/obj/weapon/whip")->wield();
	
}

void greeting(object ob)
{
	object me, room1;
	if( !ob || !objectp(ob) ) return;
	me = this_object();
	room1 = environment(me);

	if (room1->query("no_fight"))
		room1->set("no_fight", 0);

	if (interactive(ob))
	{
		command("say 你这家伙站住，让大爷我宰了你！！！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       

}
