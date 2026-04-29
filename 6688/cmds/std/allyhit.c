// allyhit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_valid_ally(object);

int main(object me, string arg)
{
	string type, attack_skill,attack_skill1,parry_skill,parry_skill1;
	mapping prepare;
	object *team,*ob,weapon,obj,env;
	int i,j,coefficient=0,temp,amount;

	seteuid(getuid());

	if( (env=environment(me))->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if(!arg || !objectp(obj = present(arg, env)))
		return notify_fail("你想攻击谁？\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "已经这样了你还要打，过分了点吧？\n"); 

	if(obj==me)	return notify_fail("打自己？别这么想不开。\n");

	if(!me->is_team_leader())
		return notify_fail("你必须是领队才行。\n");

	team=me->query_team();
	ob=team;
	i=sizeof(team);
	while(i--)
		if( !present(team[i], env) ) ob-=({team[i]});

	team=ob;
	if((amount=sizeof(team))<2) return notify_fail("人数太少无法联合攻敌。\n");

	if(member_array(obj,team)!=-1)
		return notify_fail("自己队伍中的人你也要打？\n");

	if( (coefficient = check_valid_ally(me)) <= 10  )
		return notify_fail("因为各队员的功夫不能相互配合，无法联合攻敌。\n");	

        for(i=1;i<sizeof(team);i++)
                team[0]->ally_ob(team[i],coefficient);

        for(i=0;i<sizeof(team);i++)
        {
                team[i]->fight_ob(obj);
                obj->fight_ob(team[i]);
        }

        message_vision(HIW "在$N带领下\n  " NOR +
                        implode(team->short(), "\n  ") +
                        HIW "\n开始对$n发起联合进攻。\n" NOR,me,obj);
        return 1;
}

int check_valid_ally(object me)
{
        string type, attack_skill,attack_skill1,parry_skill,parry_skill1;
        mapping prepare;
        object *team,*ob,weapon,obj,env;
        int i,j,coefficient=0,temp,amount;


        team=me->query_team();
        ob=team;
        i=sizeof(team);
	if( i<2 ) return 0;
        while(i--)
                if( !present(team[i], environment(me)) ) ob-=({team[i]});
	amount = sizeof(ob);
	team = ob;
	if( amount < 2 ) return 0;
	for(i=0;i<(amount-1);i++)
	{
		prepare = team[i]->query_skill_prepare();	
		if (!prepare) prepare = ([]);
		if( weapon = team[i]->query_temp("weapon") ) type = weapon->query("skill_type");
	        else if ( sizeof(prepare) == 0) type = "unarmed";
        	else type = (keys(prepare))[0];

		attack_skill = team[i]->query_skill_mapped(type);
		parry_skill = team[i]->query_skill_mapped("parry");

		ob-=({ob[0]});
		temp=0;
		for(j=0;j<sizeof(ob);j++)
		{
			prepare = ob[j]->query_skill_prepare();	
			if (!prepare) prepare = ([]);
			if( weapon = ob[j]->query_temp("weapon") ) type = weapon->query("skill_type");
		        else if ( sizeof(prepare) == 0) type = "unarmed";
        		else type = (keys(prepare))[0];

			attack_skill1 = ob[j]->query_skill_mapped(type);
			parry_skill1 = ob[j]->query_skill_mapped("parry");
			if( !stringp(attack_skill)
				|| !stringp(parry_skill)
				|| !stringp(attack_skill1)
				|| !stringp(parry_skill1) )
				return 0;

			if( !SKILL_D(attack_skill)->query_ally(attack_skill1,amount)
				|| !SKILL_D(attack_skill1)->query_ally(attack_skill,amount)
				|| !SKILL_D(parry_skill)->query_ally(parry_skill1,amount)
				|| !SKILL_D(parry_skill1)->query_ally(parry_skill,amount) )
				return 0;

			temp += (SKILL_D(attack_skill)->query_ally(attack_skill1,amount)
				+SKILL_D(parry_skill)->query_ally(parry_skill1,amount))/2;
		}
		coefficient += temp/sizeof(ob);
	}
        coefficient += (SKILL_D(attack_skill1)->query_ally(attack_skill,amount)
                +SKILL_D(parry_skill1)->query_ally(parry_skill,amount))/2;

	return coefficient;
}

int help(object me)
{
  write(@HELP
指令格式 : allyhit <人物>
 
这个指令让你带领一支队伍攻敌。但是你必须首先组队,并且队伍中的任意两人的
攻击功夫必须能与对方的招架功夫相互配合。

其他相关指令: team
HELP
    );
    return 1;
}
 
