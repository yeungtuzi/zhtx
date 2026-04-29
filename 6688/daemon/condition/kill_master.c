#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	me->apply_condition("kill_master", duration - 1);
	if(!(duration - 1))
	{

		if(me->is_fighting())
		{
			me->apply_condition("kill_master",1);
			return CND_CONTINUE;
		}
		else
		{
			int amount,i,guarder_exp=0,flag=0;
			object *usr,*member=({}),ob;
			string *killer;

	                usr=users();
        	        for(i=0;i<sizeof(usr);i++)
                	{
                        	if(usr[i]->query("family/family_name")==me->query("family/family_name"))
	                        {
					if(usr[i]->query_temp("guarded_master"))
					{
						member += ({usr[i]});
                		                usr[i]->delete_temp("guarded_master");
						if(guarder_exp < usr[i]->query("combat_exp"))
							guarder_exp = usr[i]->query("combat_exp");
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

			killer=me->query_temp("killmaster/killer");
			for(i=0;i<sizeof(killer);i++)
			{
				if((ob=find_player(killer[i])) && guarder_exp)
				{
					amount=10*ob->query("combat_exp")/(guarder_exp+1);
					ob->add("faith",-amount);
					tell_object(ob,sprintf(HIW" 你被惩罚了%d点师门忠诚度\n"NOR,amount));
					flag=1;
				}
			}
			if(flag)
			{
				for(i=0;i<sizeof(member);i++)
				{
					amount=10*me->query_temp("killmaster/killer_exp")/(member[i]->query("combat_exp")+1);
					member[i]->add("faith",amount);
					tell_object(member[i],sprintf(HIW" 你被奖励了%d点师门忠诚度\n"NOR,amount));
				}
			}
	                me->delete_temp("killmaster");
			return 0;
		}
        }

	return CND_CONTINUE;
}