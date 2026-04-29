inherit NPC;
#include <ansi.h>;

string grade="little";
mixed winer=0,fighter=0;
string *little=({}),*young=({}),*old=({});
int selectplayer(int is_winer);
int seekplayer(mixed str);
int race();
int bonus(object);


void create()
{
	set_name("公平子", ({ "gongpingzi", "zi", "gong" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",60000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_kee", 800);
	set("max_gin", 800);
	set("max_force", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("no_get",1);

	setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/changjian")->wield();
}


void init()
{
	add_action("do_zhaokai","zhaokai");
	add_action("do_add","add");
	add_action("do_retreat","retreat");
	add_action("do_qu","qu");
        add_action("do_halt", "halt");
	add_action("do_study","study");
	add_action("do_practice","practice");
	add_action("do_update","update");

}

int do_update(string arg)
{
	if( query("in_race") )
	{
	write("比武期间不能在这update，如果真需要的话，可以先smash公平子，再update。\n");
	return 1;
	}
	return 0;
}

int do_practice(string arg)
{
	if ( query("in_race") )
	{
		write("不能在这练武。\n");
		return 1;
	}
	return 0;
}

int do_study(string arg)
{
	if ( query("in_race") )
	{
		write("这不是读书的地方。\n");
		return 1;
	}
	return 0;
}

int do_zhaokai(string arg)
{
	int time;

	if ( !wizardp(this_player()) ) return notify_fail("你无权召开比武大会！\n");
	if ( query("in_race") )	return notify_fail("现在正在召开比武大会！\n");
	if(!arg || sscanf(arg, "%d", time)!=1 )
		return notify_fail("zhaokai <几秒(即过多长时间正式开始)> \n");
	if(time<1) return notify_fail("时间必须大于1。\n");
	command("chat 好，现在比武大会即将开始，过一会全体集合！\n");
	set("in_race",1);
	remove_call_out("summon");
	call_out("summon",time);
	return 1;
}

int summon()
{
	object *ob,env;
	int i;
	ob = users();
	i=sizeof(ob);
	env=environment();
	command("chat 好，现在开始集合！");
	while(i-- )
	{
		if(!ob[i]->query("env/no_biwu"))
		{
			tell_object(ob[i],"去集合啦。\n");
			ob[i]->move(env,1);
		}
	}
	remove_call_out("start");
	call_out("start",10);
	return 1;
}

int start()
{
	object *ob,obj;
	int i;
	command("chat 现在比武正式开始。");
	ob=users();
	i=sizeof(ob);
	while(i--)
	{
		if( ob[i]->query("age")<18 && !wizardp(ob[i])
			&& !ob[i]->query("env/no_biwu"))
		 	little+=({ob[i]->query("id")});
		else if( ob[i]->query("age")<25 && !wizardp(ob[i])
			&& !ob[i]->query("env/no_biwu") )
		 	young+=({ob[i]->query("id")});
		else
			if( !wizardp(ob[i]) && !ob[i]->query("env/no_biwu"))
			 	old+=({ob[i]->query("id")});
	}
	grade="little";
	if (selectplayer(1))
	{
		command("chat 先进行少年组的比赛。");
		obj=find_player(winer);
		command("chat 少年组的擂主是"+obj->query("name"));
		grade="little";
	}
	else
	{
		command("chat 少年组人数不够,取消少年组的比赛。");
		grade="young";
		if (selectplayer(1))
		{
			command("chat 现在进行青年组的比赛。");
			obj=find_player(winer);
			command("chat 青年组的擂主是"+obj->query("name"));
			grade="young";
		}
		else
		{
			command("chat 青年组人数不够,取消青年组的比赛。");
			grade="old";
			if (selectplayer(1))
			{
				command("chat 现在进行成年组的比赛。");
				obj=find_player(winer);
				command("chat 成年组的擂主是"+obj->query("name"));
				grade="old";
			}
			else
			{
				command("chat 成年组人数不够,取消成年组的比赛。");
				command("chat 本次武林大会到此结束。");
				delete("in_race");
				return 1;
			}
		}
	
	}

	race();
	return 1;
}

int race()
{
	object ob1,ob2,ob;
	if(grade=="little")
	{
		if(!selectplayer(0))
		{
			if(grade=="little" && stringp(winer) )
			{
				ob=find_player(winer);
				command("chat 少年组的冠军是"+ob->query("name"));
				bonus(ob);
			}
			grade="young";
			if (selectplayer(1))
			{
				command("chat 现在进行青年组的比赛。");
				ob=find_player(winer);
				command("chat 青年组的擂主是"+ob->query("name"));
				grade="young";
			}
			else
			{
				command("chat 青年组人数不够,取消青年组的比赛。");
				grade="old";
				if (selectplayer(1))
				{
					command("chat 现在进行成年组的比赛。");
					ob=find_player(winer);
					command("chat 成年组的擂主是"+ob->query("name"));
					grade="old";
				}
				else
				{
					command("chat 成年组人数不够,取消成年组的比赛。");
					command("chat 本次武林大会到此结束。");
					delete("in_race");
					return 1;
				}
			}
		}	
	}
	if(grade=="young")
	{
		if(!selectplayer(0))
		{
			if(grade=="young" && stringp(winer) )
			{
				ob=find_player(winer);
				command("chat 青年组的冠军是"+ob->query("name"));
				bonus(ob);
			}
			grade="old";
			if (selectplayer(1))
			{
				command("chat 现在进行成年组的比赛。");
				ob=find_player(winer);
				command("chat 成年组的擂主是"+ob->query("name"));
				grade="old";
			}
			else
			{
				command("chat 成年组人数不够,取消成年组的比赛。");
				command("chat 本次武林大会到此结束。");
				delete("in_race");
				return 1;
			}
		}
	}
	if(grade=="old")
	{
		if(!selectplayer(0))
		{
			if(grade=="old" && stringp(winer) )
			{
				ob=find_player(winer);
				command("chat 成年组的冠军是"+ob->query("name"));
				bonus(ob);
			}
			command("chat 本次武林大会到此结束。");
			delete("in_race");
			return 1;
		}

	}

	if(!stringp(winer) ||  !stringp(fighter) ) return 1;
	ob1=find_player(winer);
	ob2=find_player(fighter);

	ob1->set("gin",ob1->query("max_gin"));
	ob1->set("eff_gin",ob1->query("max_gin"));
	ob1->set("kee",ob1->query("max_kee"));
	ob1->set("eff_kee",ob1->query("max_kee"));
	ob1->set("sen",ob1->query("max_sen"));
	ob1->set("eff_sen",ob1->query("max_sen"));
	ob1->set("atman",ob1->query("max_atman"));
	ob1->set("force",ob1->query("max_force"));
	ob1->set("mana",ob1->query("max_mana"));
	ob1->set("food",ob1->max_food_capacity());
	ob1->set("water",ob1->max_water_capacity());
	ob2->set("gin",ob2->query("max_gin"));
	ob2->set("eff_gin",ob2->query("max_gin"));
	ob2->set("kee",ob2->query("max_kee"));
	ob2->set("eff_kee",ob2->query("max_kee"));
	ob2->set("sen",ob2->query("max_sen"));
	ob2->set("eff_sen",ob2->query("max_sen"));
	ob2->set("atman",ob2->query("max_atman"));
	ob2->set("force",ob2->query("max_force"));
	ob2->set("mana",ob2->query("max_mana"));
	ob2->set("food",ob2->max_food_capacity());
	ob2->set("water",ob2->max_water_capacity());
	remove_call_out("bihua");
	call_out("bihua",10);
	command("chat " + ob2->query("name") 
		+ "准备，你将向" + ob1->query("name") + "挑战！\n");

	return 1;
}

int bihua()
{
	object ob1,ob2;
	if(!find_player(winer) && !find_player(fighter) )
	{
		command("chat  "+winer+"和"+fighter+"双双退线，比赛被迫终止。");
		delete("in_race");
		return 1;
	}
	if( !(ob1=find_player(winer)) )
	{
		command("chat " + winer + "退线了！\n");
		winer=find_player(fighter)->query("id");
		race();
		return 1;
	}
	if( !(ob2=find_player(fighter)) )
	{
		command("chat " + fighter + "退线了！\n");
		race();
		return 1;
	}
	if(!present(winer,environment())) ob1->move(environment());
	if(!present(fighter,environment())) ob2->move(environment());
	command("chat " + ob2->query("name") 
		+ "开始向" + ob1->query("name") + "挑战！\n");
	remove_call_out("check");
	call_out("check",1,ob1,ob2);

        ob1->delete_temp("halted");
       	ob2->delete_temp("halted");
	ob1->delete_temp("be_defeated");
	ob2->delete_temp("be_defeated");

	tell_object(ob1,"该上场了。\n");
	tell_object(ob2,"该上场了。\n");
	ob1->bihua_ob(ob2);
	ob2->bihua_ob(ob1);

	return 1;
}

int check(object ob1,object ob2)
{
	if(!objectp(ob1) && !objectp(ob2) )
	{
		command("chat  "+winer+"和"+fighter+"双双退线，比赛被迫终止。");
		delete("in_race");
		return 1;
	}

	if(!objectp(ob1))
	{
		command("chat " + winer + "退线了！\n");
		winer=ob2->query("id");
		race();
		return 1;
	}
	if(!objectp(ob2))
	{
		command("chat " + fighter + "退线了！\n");
		winer=ob1->query("id");
		race();
		return 1;
	}

	if( (ob1->is_killing() || ob1->is_fighting()) 
	&& (ob2->is_killing() || ob2->is_fighting()) 
	&& present(ob1,environment()) && present(ob2,environment()) )
	{
		call_out("check",1,ob1,ob2);
		return 1;
	}

        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

	if ( !present(ob1, environment()) ) 
	{
		command("chat " + ob1->query("name") + "落荒而逃了！\n");
		winer=ob2->query("id");
		race();
		return 1;
	}

	if ( !present(ob2, environment()) ) 
	{
		command("chat " + ob2->query("name") + "落荒而逃了！\n");
		winer=ob1->query("id");
		race();
		return 1;
	}
           
        if (ob1->query_temp("halted"))
         {
	       ob1->delete_temp("halted");
               command("chat " + ob1->query("name") + 
                       "中途放弃比武！\n");
		winer=ob2->query("id");
		race();
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->query("name") + 
                       "中途放弃比武！\n");
		winer=ob1->query("id");
		race();
                return 1;
         }

	if (ob2->query_temp("be_defeated")) 
	{
		command("chat " + ob1->query("name") 
			+ "比武战胜" + ob2->query("name") + "！\n");
		ob2->delete_temp("be_defeated");
		winer=ob1->query("id");
		race();
		return 1;
	}
	if ( ob1->query_temp("be_defeated") )
	{
		command("chat " + ob2->query("name") 
			+ "比武战胜" + ob1->query("name") + "！\n");
		ob1->delete_temp("be_defeated");
		winer=ob2->query("id");
		race();
		return 1;
	}
	
	return 1;
}

int do_add(string arg)
{
	object ob;
	string who,classes;
	if(!query("in_race")) return notify_fail("现在还没进行比武大会。\n");
	if(!wizardp(this_player())) return notify_fail("只有巫师才能加名额。\n");
	if(!arg || sscanf(arg, "%s to %s", who, classes)!=2 )
		return notify_fail("格式：add <某人> to <少年组[青年组,成人组]>\n");
	if( !(ob=find_player(who)) ) return notify_fail("没这个人。\n");
	if(classes=="少年组"||classes=="little") 
	{
		little+=({who});
		command("chat "+ob->query("name")+"加入少年组。");
		return 1;
	}
	if(classes=="青年组"||classes=="young") 
	{	
		young+=({who});
		command("chat "+ob->query("name")+"加入青年组。");
		return 1;
	}
	if(classes=="成人组"||classes=="old") 
	{
		old+=({who});
		command("chat "+ob->query("name")+"加入成人组。");
		return 1;
	}
	return notify_fail("格式：add <某人> to <少年组[青年组,成人组]>\n");
}

int do_retreat(string arg)
{
	string name;
	if(!query("in_race")) return notify_fail("现在还没进行比武大会。\n");
	name=this_player()->query("id");
	little-=({name});
	young-=({name});
	old-=({name});
	command("chat "+this_player()->query("name")+"退出比赛。");
	return 1;
}

int do_qu(string arg)
{
	object me=this_player();
	if(!query("in_race")) return notify_fail("现在还没进行比武大会。\n");
	if(me->query_temp("get_weapon") ) return notify_fail("你已经拿了一样了。\n");
	if(arg=="sword")
	{
		new("/obj/weapon/sword")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="blade")
	{
		new("/obj/weapon/gangdao")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="whip")
	{
		new("/obj/weapon/whip")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="hammer")
	{
		new("/obj/weapon/hammer")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="xiao")
	{
		new("/obj/weapon/yuxiao")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="spear")
	{
		new("/obj/weapon/spear")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="gangzhang")
	{
		new("/obj/weapon/gangzhang")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="staff")
	{
		new("/obj/weapon/staff")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	if(arg=="fangtianji")
	{
		new("/obj/weapon/fangtianji")->move(me);
		me->set_temp("get_weapon",1);
		tell_object(me,"你从兵器架上取下一样武器。\n");
		return 1;
	}
	return notify_fail("找不到你要的。\n");
}

int do_halt()
{
	object me = this_player();
	if (me->is_fighting() || me->is_killing())
	{
		me->set_temp("halted",1);
		me->remove_all_killer();
		message_vision("$N向後一跃，离开战圈罢手不斗了。\n", me);
	}
	return 1;
}

int selectplayer(int is_winer)
{
	mixed player;
	if(grade=="little")
	{
		if(sizeof(little))
			player=little[random(sizeof(little))];
		else
			player=0;
		while(!seekplayer(player))
		{
			little-=({player});
			if(!sizeof(little)) {player=0;break;}
			player=little[random(sizeof(little))];
		}
		little-=({player});
		if(is_winer)
		{
			winer=player;
			if(sizeof(little))  return 1;
			else  return 0;
		}
		else
		{
			fighter=player;
			if(stringp(fighter))  return 1;
			else return 0;
		}
	}
	if(grade=="young")
	{
		if(sizeof(young))
			player=young[random(sizeof(young))];
		else
			player=0;
		while(!seekplayer(player))
		{
			young-=({player});
			if(!sizeof(young)) {player=0;break;}
			player=young[random(sizeof(young))];
		}
		young-=({player});
		if(is_winer)
		{
			winer=player;
			if(sizeof(young))  return 1;
			else  return 0;
		}
		else
		{
			fighter=player;
			if(stringp(fighter))  return 1;
			else return 0;
		}
	}
	if(grade=="old")
	{
		if(sizeof(old))
			player=old[random(sizeof(old))];
		else
			player=0;
		while(!seekplayer(player))
		{
			old-=({player});
			if(!sizeof(old)) {player=0;break;}
			player=old[random(sizeof(old))];
		}
		old-=({player});
		if(is_winer)
		{
			winer=player;
			if(sizeof(old))  return 1;
			else  return 0;
		}
		else
		{
			fighter=player;
			if(stringp(fighter))  return 1;
			else return 0;
		}
	}
	return 0;
}

int seekplayer(mixed name)
{
	object ob;
	if( stringp(name) && (ob=find_player(name)) )
	{
		if(!present(name,environment())) ob->move(environment());
		return 1;
	}
	return 0;
}

int bonus(object ob)
{
	new("/d/shaolin/obj/puti-zi")->move(ob);
	tell_object(ob,"你得到了奖励。");
	return 1;
}