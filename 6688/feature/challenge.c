#include <ansi.h>;
#include <dbase.h>

mapping list=([]);

void give_reward(object ob1,object ob2,int xishu);

int killing_master(object ob)
{
	object me=this_object();

	if( me->query("family/family_name") && (int)ob->query("faith") > 0
		&& (int)ob->query("combat_exp") >= (int)me->query("combat_exp")/10
		&& userp(ob) )
	{
		int i;
		object *usr,*member=({});

                usr=users();
       	        for(i=0;i<sizeof(usr);i++)
               	{
                       	if(usr[i]->query("family/family_name")==me->query("family/family_name"))
                        {
				if(usr[i]==me) continue;
				member += ({usr[i]});

                        }
       	        }
		member += ({me});
		message("menpai", HIR "【门派】" + me->name(1) + "：" 
			+((ob->query("family/family_name"))?(ob->query("family/family_name")+"弟子"):"")
			+ob->name(1)+"前来挑衅，本门弟子速来解围！\n"NOR,member);

		tell_object(ob,HIW""+me->name(1)+"对你嘿嘿冷笑了几声。\n"NOR);
		if(me->query_temp("killmaster/killer_exp") < ob->query("combat_exp"))
			me->set_temp("killmaster/killer_exp",ob->query("combat_exp"));
		if(!me->query_temp("killmaster/killer"))
			me->set_temp("killmaster/killer",({ob->query("id")}));
		else if( member_array(ob->query("id"), me->query_temp("killmaster/killer"))==-1)
			me->add_temp("killmaster/killer",({ob->query("id")}));

		remove_call_out("killing_me");
		call_out("killing_me",1);
	}
	return 1;
}


int killing_me()
{
	object me=this_object();
	int amount,i,killers_exp=0,flag=0,total_amount=0;
	object *usr,*member=({}),ob,*enemy,*killers=({});
	mapping reward=([]);
	string *killer;

	if(me->is_fighting())
	{
		enemy=me->query_enemy();
		flag=0;
		for(i=0;i<sizeof(enemy);i++)
		{
			if(present(enemy[i],environment()))
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			call_out("killing_me",1);
			return 1;
		}
	}

	usr=users();
	for(i=0;i<sizeof(usr);i++)
        {
               	if(usr[i]->query("family/family_name")==me->query("family/family_name"))
                {
			if(usr[i]->query_temp("guarded_master"))
			{
				member += ({usr[i]});
               	                usr[i]->delete_temp("guarded_master");
			}
			continue;
                }
		usr[i]=0;
        }
	usr -= ({0});
	usr -= ({me});
	usr += ({me});
	message("menpai", HIR "【门派】" + me->name(1) + "：" 
		+"本门危机解除！\n"NOR, usr);

	for(i=0;i<sizeof(member);i++)
	{
		amount=10*me->query_temp("killmaster/killer_exp")/(member[i]->query("combat_exp")+1);
		if(amount>1) amount = amount*3/5;
		if(amount>25) amount=25;
		total_amount += amount*5/3;
		reward[member[i]->query("id")]=amount;
	}

	killer=me->query_temp("killmaster/killer");

	for(i=0;i<sizeof(killer);i++)
	{
		if((ob=find_player(killer[i])))
		{
			killers += ({ob});
			killers_exp += ob->query("combat_exp");
		}
	}
	flag=0;
	for(i=0;i<sizeof(killers);i++)
	{
		amount=total_amount*killers[i]->query("combat_exp")/killers_exp;
		if(amount)
		{
			killers[i]->add("faith",-amount);
			tell_object(killers[i],sprintf(HIW" 你被惩罚了%d点师门忠诚度\n"NOR,amount));
			flag=1;
		}
	}
	if( flag )
	{
		for(i=0;i<sizeof(member);i++)
		{
//			amount=reward[member[i]->query("id")];
//			member[i]->add("faith",amount);
			tell_object(member[i],HIW" 你奋不顾身保卫师门的英勇行为获得了本门的一致赞赏.\n "NOR);
		}
	}
	me->delete_temp("killmaster");
	return 1;
}

int menpai_punish()
{
	int amount,i;
	object *usr,*member=({}),me=this_object();

	if(!me->query_temp("killmaster") || !me->query("family/family_name")) return 1;

	usr=users();
	for(i=0;i<sizeof(usr);i++)
	{
		if(usr[i]->query("family/family_name")==me->query("family/family_name"))
		{
			if(usr[i]==me) continue;
			member += ({usr[i]});
			if(me->query_temp("killmaster/killer")
			   && member_array(usr[i]->query("id"), me->query_temp("killmaster/killer"))!=-1)
			{
				amount=50 + random(200);
				usr[i]->add("faith",-amount);
				tell_object(usr[i],sprintf(HIW" 你被惩罚了%d点师门忠诚度\n"NOR,amount));
				continue;
			}

			if(usr[i]->query_temp("guarded_master"))
			{
				usr[i]->delete_temp("guarded_master");
				if(usr[i]->is_ghost())
				{
					//amount=2*me->query_temp("killmaster/killer_exp")/(usr[i]->query("combat_exp")+1);
					//if(amount>1) amount = amount*3/5;
					//if(amount>25) amount=25;
					//usr[i]->add("faith",amount);
					tell_object(member[i],HIW" 你奋不顾身保卫师门的英勇行为获得了本门的一致赞赏.\n "NOR);
				}
				else
				{
					amount=2*usr[i]->query("combat_exp")/(me->query_temp("killmaster/killer_exp")+1);
					if(amount>50) amount=50;
					if(amount)
					{
						usr[i]->add("faith",-amount);
						tell_object(usr[i],sprintf(HIW" 你被惩罚了%d点师门忠诚度\n"NOR,amount));
					}
				}
			}
			else
			{
				amount=10*usr[i]->query("combat_exp")/(me->query_temp("killmaster/killer_exp")+1);
				if(amount>50) amount=50;
				if(amount)
				{
					usr[i]->add("faith",-amount);
					tell_object(usr[i],sprintf(HIW" 你被惩罚了%d点师门忠诚度\n"NOR,amount));
				}
			}
		}
	}
	member += ({me});
	message("menpai", HIR "【门派】" + me->name(1)
		+"在倒地的瞬间环顾了一下四周，眼里透出一丝绝望。\n"NOR, member);
	me->delete_temp("killermaster");
	return 1;
}



int tiaozhan(object ob1)
{     
	object ob2,*member;
	int exp,i,faith;
	string id;

	exp=(int)ob1->query("combat_exp");

	if(exp<100000)
	{
		tell_object(ob1,"你没资格挑战。\n");
		return 1;
	}
	faith=(int)ob1->query("faith");
	if(faith < 300) {
		tell_object(ob1,"你师门忠诚度不够，不能代表本门。\n");
		return 1;
	}

        if ( (int)ob1->query_condition("have_challenge" ) > 0 )
	{
		tell_object(ob1,"这么快又要挑战，还是好好去练功吧。\n");
		return 1;
	}

	if ( query_temp("busy") ) 
	{
		tell_object(ob1,"现在正有人在挑战本门。\n");
		return 1;
	}

	if(ob1->query("family/family_name")==query("family/family_name"))
	{
		tell_object(ob1,"别胡闹了，快去练功吧。\n");
		return 1;
	}

	id=ob1->query("id");

	member=users();
	for ( i=0;i<sizeof(member);i++)
	{
		if(member[i]->query("family/family_name")==query("family/family_name")
			&& member[i]->query("combat_exp") >= exp*8/10
			&& !(!undefinedp(list[id]) && member_array(member[i]->query("id"), list[id])!=-1)
			&& !member[i]->is_ghost()
			&& !member[i]->query_temp("block_msg/all")
			&& !wizardp(member[i]) )
			continue;
		member[i] = 0;
	}

	member -=({0});

	if(!sizeof(member) && !undefinedp(list[id]))
	{
		int amount;
		command("chat "+HIR"我"+query("family/family_name")+
			"向"+ob1->query("family/family_name")+"低头认输，请壮士高抬贵手放我派一马。"NOR);
		map_delete(list,id);

		ob1->apply_condition("have_challenge", 500);
		amount=random(10);
		ob1->add("faith",amount);
		tell_object(ob1,sprintf(HIW" 你被奖励了%d点师门忠诚度\n"NOR,amount));

		return 1;
	}

	if(!sizeof(member))
	{
		command("chat "+HIR"我"+query("family/family_name")+
			"人才凋零，令人汗颜，壮士还是请回吧。"NOR);
		return 1;
	}

	ob2=member[random(sizeof(member))];

	command("mp "
		+((ob1->query("family/family_name"))?(ob1->query("family/family_name")+"弟子"):"")
		+ob1->name(1)+"前来挑战，本门弟子"+ob2->name(1)+"速来迎接挑战！");
	command("say 壮士稍待，我已命我派弟子"+ob2->name(1)+"火速前来迎接挑战。");

	if(undefinedp(list[id]))
		list[id] = ({ob2->query("id")});
	else
		list[id] += ({ob2->query("id")});

	set_temp("busy",1);
	set_temp("tiaozhan",ob1->query("id"));
	set_temp("yingzhan",ob2->query("id"));
	ob1->apply_condition("have_challenge", 500);

	remove_call_out("wait");
	call_out("wait",300);
	return 1;
}

void wait()
{
	object ob1,ob2;

	if(!(ob1=find_player(query_temp("tiaozhan"))) )
	{
		command("mp 由于挑战者下线,此次挑战结束.");
		delete_temp("busy");
		return;
	}
	if(!(ob2=find_player(query_temp("yingzhan"))) )
	{
		tell_object(ob1,HIW"由于迎战者下线,此次挑战结束.\n"NOR);
		delete_temp("busy");
		ob1->apply_condition("have_challenge", 0);
		return;
	}

	if( present(ob1, environment()) )
	{

		tell_object(ob1,HIW""+ob2->name(1)+"有事无法赶来，壮士请回。\n"NOR);
		command("mp "+ob2->name(1)+"临阵逃缩，丢尽我派脸面。");
		give_reward(ob1,ob2,10);
		delete_temp("busy");
		ob1->apply_condition("have_challenge", 0);
		return;
	}

	if(!present(ob1, environment()) && present(ob2, environment()) )
	{
		command("mp "+ob1->name(1)+"临阵逃缩，"+ob2->name(1)+"扬我派威名。");
		tell_object(ob1,HIW"临阵逃缩，羞羞羞!\n"NOR);
		give_reward(ob2,ob1,2);
		delete_temp("busy");
		return;
	}

	tell_object(ob1,HIW"由于挑战双方弃权，本次挑战结束。\n"NOR);
	command("mp 由于挑战双方弃权，本次挑战结束。");
	delete_temp("busy");
	return;
}

int yingzhan(object ob2)
{
	object ob1;

	if(!query_temp("busy"))
	{
		tell_object(ob2,"现在并没有人来挑战。\n");
		return 1;
	}
	if(ob2 != find_player(query_temp("yingzhan")) )
	{
		tell_object(ob2,"并没有让你来迎战。\n");
		return 1;
	}
	if(!(ob1=find_player(query_temp("tiaozhan")))
		|| !present(ob1, environment()) )
	{
		tell_object(ob2,"挑战者已经离开了。\n");
		return 1;
	}

	environment()->set("no_death",1);
	remove_call_out("wait");

	message_vision(HIR"$N开始迎接$n的挑战。\n"NOR,ob2,ob1);
	
	remove_call_out("challenge_check");
	call_out("challenge_check",1,ob1,ob2);

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");
	ob1->delete_temp("be_defeated");
	ob2->delete_temp("be_defeated");

	ob1->bihua_ob(ob2);
	ob2->bihua_ob(ob1);

	return 1;
}

void challenge_check(object ob1,object ob2)
{
	if(!objectp(ob1) && !objectp(ob2) )
	{
		command("say  挑战双方弃权，本次挑战结束。");
		environment()->delete("no_death");
		delete_temp("busy");
		return;
	}

	if(!objectp(ob1))
	{
		command("say 挑战者退线了！");
		environment()->delete("no_death");
		delete_temp("busy");
		ob2->remove_all_killer();
		return;
	}

	if(!objectp(ob2))
	{
		command("say 迎战者退线了！");
		environment()->delete("no_death");
		delete_temp("busy");
		ob1->apply_condition("have_challenge", 0);
		ob1->remove_all_killer();
		return ;
	}

	if( (ob1->is_killing() || ob1->is_fighting()) 
		&& (ob2->is_killing() || ob2->is_fighting())
		&& present(ob1,environment()) && present(ob2,environment()) )
	{
		call_out("challenge_check",1,ob1,ob2);
		return ;
	}

	delete_temp("busy");
	environment()->delete("no_death");
	ob2->remove_all_killer();
	ob1->remove_all_killer();

	if ( !present(ob1, environment()) ) 
	{
		tell_object(ob1,HIW"还是等功夫练好了，再来现眼吧。:(\n"NOR);
		command("mp "+ob1->name(1)+"被"+ob2->name(1)+"打的落荒而逃了！");
		give_reward(ob2,ob1,10);
		return ;
	}

	if ( !present(ob2, environment()) ) 
	{
		tell_object(ob1,HIW"壮士武功高强，我派甘拜下风。\n"NOR);
		command("mp "+ob2->name(1)+"被"+ob1->name(1)+"打的落荒而逃，丢我师门脸面！");
		give_reward(ob1,ob2,10);
		ob1->apply_condition("have_challenge", 0);
		return ;
	}
           
        if (ob1->query_temp("halted"))
         {
	       ob1->delete_temp("halted");
		tell_object(ob1,HIW"还是等功夫练好了，再来现眼吧。:(\n"NOR);
		command("mp "+ob1->name(1)+"被"+ob2->name(1)+"打的中途投降。");
		give_reward(ob2,ob1,10);
                return ;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
		tell_object(ob1,HIW"壮士武功高强，我派甘拜下风。\n"NOR);
		command("mp "+ob2->name(1)+"被"+ob1->name(1)+"打的中途投降，丢我师门脸面！");
		give_reward(ob1,ob2,10);
		ob1->apply_condition("have_challenge", 0);
                return ;
         }

	if ( ob1->query_temp("be_defeated") )
	{
		tell_object(ob1,HIW"还是等功夫练好了，再来现眼吧。:(\n"NOR);
		command("mp "+ob1->name(1)+"被"+ob2->name(1)+"击败。");
		ob1->delete_temp("be_defeated");
		give_reward(ob2,ob1,10);
		return ;
	}

	if (ob2->query_temp("be_defeated")) 
	{
		tell_object(ob1,HIW"壮士武功高强，我派甘拜下风。\n"NOR);
		command("mp "+ob2->name(1)+"被"+ob1->name(1)+"打败，丢我师门脸面！");
		ob2->delete_temp("be_defeated");
		give_reward(ob1,ob2,10);
		ob1->apply_condition("have_challenge", 0);
		return ;
	}
	return ;
}

int surrender(object ob)
{
	if(query_temp("busy") 
		&& (ob->query("id")==query_temp("tiaozhan") || ob->query("id")==query_temp("yingzhan"))
		&& (ob->is_fighting() || ob->is_killing()) )
	{
		ob->set_temp("halted",1);
		ob->remove_all_killer();
		message_vision("$N向後跃开，拱手道：“壮士武艺高强，在下甘拜下风。”\n", ob);
		return 1;
	}
	return 0;
}

void give_reward(object ob1,object ob2,int xishu)
{
	int amount,temp;

	amount=xishu*ob2->query("combat_exp")/(ob1->query("combat_exp")+1);
	temp=amount;
	if(amount>1) amount=amount*3/5;
	if(amount>25) amount=25;
	ob1->add("faith",amount);
	tell_object(ob1,sprintf(HIW" 你被奖励了%d点师门忠诚度\n"NOR,amount));
	amount=temp;
	if(amount)
	{
		if(amount>50) amount=50;
		ob2->add("faith",-amount);
		tell_object(ob2,sprintf(HIW" 你被惩罚了%d点师门忠诚度\n"NOR,amount));
	}
	return;
}
