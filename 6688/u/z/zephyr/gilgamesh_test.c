#include <ansi.h>
inherit NPC;

//没有敌人而离去
void leave();
//攻击敌人后离去
void depart();
int flag;

//斩铁剑
void slash(object victim,object player);

object me=this_object();


void create()
{
	set_name(CYN"兵器贩子"NOR, ({ "weaponor","bingqi fanzi"}) );
	set("long",BLK@LONG
兵器贩子是一个喜欢收集武器的人，在各地奔波寻找目的
是找寻收集纵横天下的神兵利器。他为他收集到的神兵利
器进行排名，并且为其中威力最巨的几件笔录成书，就是
传说中的纵横兵器谱。
拥有该兵器谱的人可以在战斗中得到他的帮助。
LONG NOR
	 );

	set("max_gin", 3000);
	set("max_kee", 8000);                    
	set("max_sen", 3000);
	set("max_force",5000); 
	set("max_mana",10000);
	set("mana",20000);
	set("max_atman",5000);
	set("atman",10000);
	set("force",10000);
	set("force_factor",300);     
	set("mana_factor",300);     
	set("combat_exp",29999999);
	set("cor",50);
	set("cps",50);   
	set("spi",50);
	set("per",50);
	set("str",50);
	set("age",30);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	map_skill("force", "hunyuan-yiqi");


	set_temp("apply/astral_vision", 1);


	set_temp("apply/damage",200);
	set_temp("apply/armor",200);
	set_temp("apply/armor_vs_force",200);
	set_temp("apply/attack",100);
	set_temp("apply/defense",100);
	set_temp("apply/dodge",100);
	set_temp("apply/parry",100);


	setup();
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}                          

void init()
{
	flag=1;
	return 1;
}
                             
                     
//判断对方是否玩家，如果是玩家，伤害减少一半。攻击一次并离去。如果无对手，离去。
int chat()
{       
	object *enemys,victim;
	int i, all;
	
	clean_up_enemy();
	enemys = query_enemy();
	i = sizeof(enemys);
	//解除一切敌人
	while(i--)
	{
		remove_enemy(enemys[i]);
		enemys[i]->remove_enemy(this_object());
	}	

	
	all = sizeof(enemys);

	//无敌人，离去
	if( !all ) me->leave();

	for(i=0;i<sizeof(all);i++)
	{
		victim = enemys[i];	
		me->slash(victim);
	}
}	

void depart()

{
        message("vision", "\n"+name()+YEL"一言不发，转身慢慢消失在远方天际。\n"NOR, environment());
		destruct(this_object());
}



void slash(object victim, object player)
{
		int gil_flag, lea, kar, damage, wound, gin_sen_damage, dp, v_exp, s, suck, heal,damage_bonus, self_damage, decrease;
		string sword_name,player_name,victim_name;

		player_name=player->query("name");
		victim_name=victim->query("name");
		

		s = random(6);
		//s =5;
		switch (s)
		{
			case 0: sword_name=WHT"七修剑"NOR; 
					damage = 1000 + random(500); 
					if (wizardp(player)) tell_object(player,"dam is "+damage+"\n");
					break;
			case 1: sword_name=HIW"七修剑"NOR; 
					damage = 1;
					if (wizardp(player)) tell_object(player,"dam is "+damage+"\n");
					break;
			case 2: sword_name=BLK"斩铁剑"NOR;
					damage = 1500 + random(1000); 
					if (wizardp(player)) tell_object(player,"dam is "+damage+"\n");
					break;
			case 3: sword_name=CYN"破残"NOR; 
					damage = 1 + random(3000);
					if (wizardp(player)) tell_object(player,"dam is "+damage+"\n");
					break;
			case 4: sword_name=CYN"刈鹿刀"NOR; 
					damage = 500 + random(500);
					if (wizardp(player)) tell_object(player,"dam is "+damage+"\n");
					break;
			case 5: sword_name=CYN"灵空剑"NOR; 
					damage = 300 + random(1000);
					if (wizardp(player)) tell_object(player,"dam is "+damage+"\n");
					break;
		}

		wound = damage/2;
		if (wound<1) wound = 1;

		v_exp = (int) victim->query("combat_exp");
		dp = (int) victim->query_skill("parry");
		dp = (dp*dp*dp/70);
		v_exp = v_exp/50;
		dp += v_exp;
		dp = dp/10000;

		if (dp>500)
		{
			dp=500;
		}
		//测试使用
		//message_vision(CYN"敌人防御指数"+ dp + "\n"NOR,environment());
		
		//比例攻击
		//damage = (int)victim->query("kee")/4 + random ( (int)victim->query("kee")/4);
		//wound = damage/3 + random (damage/3);
		//正常攻击

		//if( userp(victim) ) {me->leave();return;}
		if (flag)
		{
			message("vision", CYN"\n"+YEL"天边忽然闪出一道黑影，只一刹那间已到你的身边，你不禁骇然：好快！\n", environment());
			message("vision", CYN"\n"+YEL"只见此人身着一袭紧身黑衣，以黑巾蒙面，身后还背负一个宽大的包裹，正是传说中的"+name() + "。\n", environment());
			message("sound", "\n"+name() + HIW"深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼！！\n"NOR, environment());

			//增加玩家与兵器贩子的相性：
			lea=player->query("lea");
			kar=player->query("kar");
			gil_flag=player->query("gil_flag");
			gil_flag++;
			gil_flag = gil_flag + random(lea)/2 + random(kar)/4;
			if (gil_flag>5000)
			{
				gil_flag=5000;
			}
			player->set("gil_flag",gil_flag);

			flag--;
		}
		
		message("vision", "\n"+name() + CYN"如电光石火般地在" + victim_name + CYN"身旁一晃，从背后包裹中随手抽出"NOR+sword_name+CYN"一挥。\n", environment());

		if (environment())
		{
			if ( random(1000)>dp )
			{	
		//		message("vision", HIW"\n只见一道雪亮的白光划过" +victim_name+ HIW"的胸膛\n"NOR, environment());
				if (random(10)>5)
				{
					message("sound", CYN"\n只听"+ victim_name +CYN"一声惨叫，只见"NOR + sword_name + CYN"幻作一道银光在" + victim_name+CYN"胸前扫过\n"NOR, environment());
					message("sound", RED"\n鲜血从"+victim_name+RED"胸前一条细长的伤口汩汩冒出...\n\n"NOR, environment());

				}
				else 
				{	
					message("sound", CYN"\n只听"+ victim_name +CYN"一声惨叫，"NOR + sword_name + CYN"已经在" + victim_name+CYN"腰间砍出一道可怕的伤口\n"NOR, environment());
					message("sound", RED"\n鲜血如泉涌般从"+victim_name+RED"腰间的伤口喷洒出来...\n\n"NOR, environment());
				}

				if (wound > victim->query("eff_kee") )
				{
					wound=victim->query("eff_kee") - 1;
				}
				if ( damage > victim->query("kee"))
				{
					damage=victim->query("kee") - 1;
				}
				if (damage < 0 || wound < 0)
				{
					damage = 0;
					wound = 0;
				}

				victim->receive_wound("kee", wound, player);
				victim->receive_damage("kee", damage, player);

				//加各兵器特殊效果
				switch (s)
				{
				//七修剑
				case 0: gin_sen_damage=wound/10;
						if (gin_sen_damage>300)
						{
							gin_sen_damage=300;
						}
						if (gin_sen_damage<10)
						{
							gin_sen_damage=10;
						}
						victim->receive_wound("sen", gin_sen_damage, player);
						victim->receive_damage("sen", gin_sen_damage, player);
						victim->receive_wound("gin", gin_sen_damage, player);
						victim->receive_damage("gin", gin_sen_damage, player);
						if ((string) victim->query_temp("weapon"))
						{
						object weapon = victim->query_temp("weapon");
						weapon->unequip();
						message_vision(WHT"银光闪处，"+victim_name+WHT"手上的"NOR+weapon->query("name")+WHT"已被七修剑剑气所断。\n"NOR,environment());
                        weapon->move(environment(victim));
                        weapon->set("name", "断成两截的" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        weapon->set("long", weapon->query("long")+"现在却已经断成了两截，你仔细观察时，发现断口齐整，显然是被神兵所断。\n");
                        victim->reset_action();
						}
						break;

				//假七修剑
				case 1:	victim->receive_wound("sen", wound, player);
						victim->receive_damage("sen", damage, player);
						victim->receive_wound("gin", wound, player);
						victim->receive_damage("gin", damage, player);
						break;
				//斩铁剑：破甲
				case 2:	victim->start_call_out( (: call_other, __FILE__, "remove_effect", victim :), 50);
						victim->add_temp("apply/armor", -random(800));
						victim->add_temp("apply/armor_vs_force", -random(300));
						tell_object(victim, CYN"你身上的铠甲不胜斩铁剑的重创，防护能力消失甚多！\n");
						break;
				//破残：冰冻
				case 3:	victim->start_busy(random(10)); 
						tell_object(victim, CYN"你只觉得一阵严寒袭体，刹那间，仿佛置身冰窖，一时浑身僵硬，不能动弹\n");
						break;
				//刈鹿刀：
				case 4:	suck = victim->query("eff_kee")/10;
						if (suck<1)
						{
							suck=0;
						}
						heal = 1+ random (suck);
						if (heal>500)
						{
							heal=500;
						}
						if (wizardp(player)) tell_object(player,"额外伤害点： "+suck+"\n");
						if (wizardp(player)) tell_object(player,"自我疗伤点： "+heal+"\n");

						victim->receive_wound("kee", suck, player); 
						victim->receive_damage("kee", suck, player); 
						player->add("eff_kee",heal);
						if (player->query("eff_kee")>player->query("max_kee"))
						{
							player->set("eff_kee",player->query("max_kee")); 
						}
						message_vision(player_name+RED"身上泛起一圈红晕，脸色好多了。\n"NOR,environment());
						COMBAT_D->report_status(victim,player,1);						
						tell_object(victim, RED"你知觉伤口如决口之堤一般\n"NOR);
						break;
				//灵空剑
				case 5:	damage_bonus = 100 + random (victim->query("eff_kee")/5);
						if (damage_bonus<1)
						{
							damage_bonus=0;
						}
						self_damage = damage_bonus/5;
						if (self_damage>500)
						{
							self_damage=500;
						}
						if (self_damage > player->query("eff_kee"))
						{
							self_damage = player->query("eff_kee")-1;
						}
						if (self_damage<1)
						{
							self_damage=1;
						}
						if (wizardp(player)) tell_object(player,"额外伤害点： "+damage_bonus+"\n");
						if (wizardp(player)) tell_object(player,"自我伤害点： "+self_damage+"\n");

						victim->receive_wound("kee", damage_bonus, player); 
						victim->receive_damage("kee", damage_bonus, player); 
						player->receive_wound("kee", self_damage, victim);
						player->receive_damage("kee", self_damage, victim);
						message_vision(player_name+RED"无法控制灵空剑的邪气，伤人的同时也被剑气所伤。\n"NOR,environment());
						COMBAT_D->report_status(victim,player,1);						
						tell_object(victim, YEL"灵空剑上仿佛生了锯齿，你只觉伤口处皮开肉绽\n"NOR);
						break;
				}

				COMBAT_D->report_status(player,victim,1);

				message("vision", "\n"+name() + CYN"反手将"NOR + sword_name + CYN"插回背后包裹，姿势潇洒已极。\n"NOR, environment());
			}
			else 
			{
				message("vision", CYN"\n却见" + victim_name + CYN"冷笑一声，身子微微一侧，在千钧一发之刻，躲过了这致命一击\n"NOR, environment());
				message("vision", "\n"+name() + CYN"与" + victim_name + CYN"擦身而过的一刹那间，" + victim_name + CYN"手上似乎多了一物，轻轻一晃\n"NOR, environment());
				message("vision", "\n"NOR + sword_name + HIW"旋转着从天空坠落插在"+ victim_name +HIW"身边的地上，颤动不已\n"NOR, environment());
				message("vision", "\n"+name() + HIR"胸前忽地喷出一股鲜血，洒向半空中，形成一片凄美的红雨\n"NOR, environment());
				
				if( !userp(victim) )
				{
					victim->add("combat_exp",50000);
					victim->add("max_force",100);
					victim->add("force",300);
					victim->add("force_factor",10);
					victim->add("bellicosity",500);
				}
				//减少玩家与兵器贩子的相性：
				lea=player->query("lea");
				kar=player->query("kar");
				gil_flag=player->query("gil_flag");
				gil_flag--;
				decrease = 50 - random(lea) - random(kar);
				if (decrease < 10 )
					decrease = 10;
				if (decrease > 30 )
					decrease = 30;

				gil_flag -= decrease;
				if (gil_flag < 1)
					gil_flag = 1;
				player->set("gil_flag",gil_flag);
				destruct(this_object());
			}
		}
		else
		{
			me->leave();
		}
}


void leave()

{
        message("vision", "\n"+name()+YEL"一言不发，转身慢慢消失在远方天际。\n"NOR, environment());
		destruct(this_object());

}

void remove_effect(object victim)
{
	message_vision(CYN"恢复armor\n"NOR,environment());
	victim->add_temp("apply/armor", 200);
	victim->add_temp("apply/armor_vs_force", 100);
	tell_object(victim, CYN"你身上被斩铁剑造成的创伤慢慢的恢复了\n");
}
