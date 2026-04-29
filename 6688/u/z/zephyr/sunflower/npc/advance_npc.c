#include <combat.h>
inherit NPC;
void consider();
void heal();
int do_hit(string arg);
void setup()
{
	int *force=({4500,5500,6500,8500,12000,15000});
	int *exp=({7,12,18,25,40,60});
	int lvl,t;
	::setup();
	set("no_baowu",1);
	lvl=query("level");
	if(lvl>5||lvl<1) lvl=6;
	//设置hp参数
	t=force[6-lvl]+random(1000);
	set("max_force",t);
	set("force",t*2);
	set("max_kee",t-500);
	set("eff_kee",t-500);
	set("kee",t-500);
	t=(7-lvl)*800+random(500);
	set("max_mana",t);
	set("mana",t*2);
	set("max_atman",t);
	set("atman",t*2);
	set("max_gin",t/3);
	set("eff_gin",t/3);
	set("gin",t/3);
	set("max_sen",t/3);
	set("eff_sen",t/3);
	set("sen",t/3);
	set("force_factor",250+(6-lvl)*50+random(50));
	set("combat_exp",exp[6-lvl]*800000+random(exp[6-lvl]*800000)/2);
	//设置天赋
	t=60+(6-lvl)*15+random(10);
	set("str",t);
	set("cps",t);
	set("cor",t);
	set("con",t);
	set("spi",t);
	set("kar",t);
	set("int",t);
	//设置adv_attrib参数
	t=exp[6-lvl]*20+random(50);
	set("adv_attrib/parry",t);
	set("adv_attrib/armor",t);
	set("adv_attrib/armor_vs_force",t);
	set("adv_attrib/armor_vs_spells",t);
	if(query("gender")=="男性")
	{
		set("adv_attrib/attack",t+300);
		set("adv_attrib/damage",t+300);
		set("adv_attrib/dodge",t-50);
		set("adv_attrib/defense",t-50);
	}
	else
	{
		set("adv_attrib/attack",t+100);
		set("adv_attrib/damage",t+100);
		set("adv_attrib/dodge",t+200);
		set("adv_attrib/defense",t+200);
	}
	//设置apply参数
	t=exp[6-lvl]*15+random(200);
	set_temp("apply/armor",2000+(t+2*random(t))/2 );
	set_temp("apply/armor_vs_force",1000+t);
	set_temp("apply/armor_vs_spells",1000+t);
	set_temp("apply/damage",1000+(t+random(t))/2);
	t=70+(6-lvl)*10+random(20);
	set_temp("apply/attack",200+t);
	set_temp("apply/defense",100+t);
	//设置基本skills
	t=230+(6-lvl)*25;
	set_skill("force",t+random(10));
	set_skill("cuff",t+random(10));
	set_skill("strike",t+random(10));
	set_skill("perception",t+random(10));
	if(lvl<3)
		set_skill("qimen-bagua",250);
	else if(lvl==3)
		set_skill("qimen-bagua",230);
	else
		set_skill("qimen-bagua",200);
	set_skill("dodge",t+random(10));
	set_skill("parry",t+random(10));
	set_skill("move",t+random(10));
	set_skill("sword",t+random(10));

    set("chat_chance_combat", 80);  
	set("chat_msg_combat", ({
		(: consider :),
	}) );
}

void consider()
{
	object* all,who,me,weapon,it;
	int i,flag=0,kee=20000,n=0,m=0;
	string type,cmd;

	me=this_object();
	all=me->query_enemy(); 
	//charge 气最少的player
	for(i=0;i<sizeof(all);i++)
	{
		if(!userp(all[i]))
		{
//			all[i]->delete_temp("apply");
//			all[i]->set("force_factor",1);
//			all[i]->set("force",1000);
//			flag=1;
		}
		if(userp(all[i])&&(all[i]->query("eff_kee")<kee))
		{
			kee=all[i]->query("eff_kee");
			who=all[i];
		}			
		n++;	
		if(userp(all[i])&&all[i]->query_temp("block_msg/all"))
		{
			it=all[i];
			m=1;
		}
	}
	if(n>1)	charge_ob(who);
	if(m) 
	{
		COMBAT_D->do_attack(me, it, me->query_temp("weapon"),TYPE_QUICK);
	}
	if(!objectp(query_temp("weapon")))
	{
		if(stringp(type=query("weapon_type")))
		{
			weapon=new("/obj/weapon/"+type);
			weapon->move(this_object());
			command("wield "+weapon->query("id"));
		}
	}
	if(!flag&&stringp(cmd=query("percmd")))
		command(cmd);
	heal();
}

void heal()
{
	object ob=this_object();
	if (ob->query("kee") < ob->query("eff_kee")*60/100)
	{	command("exert recover");
		return;
	}
	if (ob->query("gin") < ob->query("eff_gin")*60/100)
		command("exert regenerate");
	if (ob->query("sen") < ob->query("eff_sen")*60/100)
		command("exert refresh");
	return;
}

