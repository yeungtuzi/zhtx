// mystsword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"暮雪三叹",
		"action":		"$N使一招「暮雪三叹」，手中$w急如骤雨般地刺向$n$l",
		"dodge":		20,
		"force":		40,
		"damage":		30,
		"damage_type":	"刺伤"
	]),
	([	"name":			"处子弄笛",
		"action":		"$N身形一晃，一招「处子弄笛」向$n$l刺出一剑",
		"dodge":		20,
		"force":		50,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
	([	"name":			"阳谷白练",
		"action":		"$N舞动$w，一招「阳谷白练」挟著闪闪剑光刺向$n的$l",
		"dodge":		20,
		"force":		70,
		"damage":		50,
		"damage_type":	"刺伤"
	]),
	([	"name":			"薰容逐电",
		"action":		"$N手中$w一个圈转，使出「薰容逐电」中锋直进刺向$n的$l",
		"dodge":		20,
		"force":		80,
		"damage":		55,
		"damage_type":	"刺伤"
	]),
	
	([	"name":			"满地落花红带雨",
		"action":		"$N曼声吟道：「满地落花红－带－雨！」，$w挽起的数十朵剑花立刻带起了一片绚丽的血雨，向$n周身撒去",
		"dodge":		20,
		"attack":		15,
		"force":		180,
		"damage":		155,
		"damage_type":	"刺伤",
		"lvl":		221,
	]),

});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("mystforce",1) < 30 )
		return notify_fail("你的步玄心法火候还不够。\n");

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法练小步玄剑。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("mystsword",1);

        for(i = sizeof(action); i > 0; i--)
                        if(level > action[i-1]["lvl"])
                                return action[NewRandom(i, 20, level/5)];
}

/*
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
*/

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习小步玄剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍小步玄剑。\n");
	return 1;
}

mapping enable_req() {

	return( ([ 
		"force":"mystforce",	
	]) );

}

mapping level_req(int level) {

	return( ([
		"mystforce":10,	
	]) );
}

int query_faith_req(int skill) {
	return 3;
}
