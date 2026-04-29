// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「红叶晚萧萧」，手中$w幻一条疾光刺向$n的$l",
		"dodge":		-20,
		"force":		40,		
		"damage":		20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出摩尼剑法中的「长亭酒一瓢」，$w连挥剑光霍霍斩向$n的$l",
		"dodge":		-20,
		"force":		40,		
		"damage":		40,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「残云归太华」，纵身飘开数尺，手中$w斩向$n的$l",
		"dodge":		-30,
		"force":		20,		
		"damage":		60,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w中宫直进，一式「疏雨过中条」对准$n的$l刺出一剑",
		"dodge":		-20,
		"force":		40,
		"damage":		80,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N纵身一跃，手中$w一招「树色随山迥」对准$n的$l斜斜刺出一剑",
		"dodge":		-20,
		"force":		60,
		"damage":		100,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的$w凭空一指，左手剑诀，右手一招「河声入海遥」刺向$n的$l",
		"dodge":		20,
		"force":		80,		
		"damage":		120,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        object me;
        
        me = this_player();
        if( (me->query_skill_mapped("force") != "jiuyang-shengong") && (me->query_skill_mapped("force") != "moni-xinfa"))
	{
	       write("关山神掌只能配合九阳神功或者摩尼圣火心法使用。\n");
	       return 0;
	}

	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;
	
	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 100 )
		return notify_fail("你的内力或气不够，没有办法练习摩尼剑法。\n");
	me->receive_damage("kee", 30);
	write("你按著所学练了一遍摩尼剑法。\n");
	return 1;
}
