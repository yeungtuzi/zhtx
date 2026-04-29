// taosword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「群邪辟易」，手中$w幻出一道银光刺向$n的$l",
		"damage":		30,
		"force":		40,
                "attack":                20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出天师剑法中的「降魔荡寇」，$w去势如电斩向$n的$l",
		"damage":		30,
		"force":		40,
                "attack":                20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「三清归真」，左手一捻剑诀，右手$w斩向$n的$l",
		"damage":		20,
		"force":		40,
                "attack":                20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w中宫直进，一招「一阳至元」对准$n的$l刺出一剑",
		"damage":		30,
		"force":		40,
                "attack":                20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N身形一矮，手中$w一招「众土护佑」对准$n的$l斜斜撩出一剑",
		"damage":		30,
		"force":		40,
                "attack":                20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N手中$w望空一指，使出「七星截煞」斩向$n的$l",
		"damage":		40,
		"force":		40,
                "attack":                20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w一翻，使一招「幽冥路远」反手一剑刺向$n$l",
		"damage":		30,
		"force":		40,
                "attack":                20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N身形一转，手中$w使一招「天人合一」画出一道光弧往$n的$l斩去",
		"damage":		20,
		"force":		40,
                "attack":                20,
		"damage_type":	"割伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练天师剑法。\n");

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
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习天师剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("taoist") + "/taosword/" + action;
}

mapping level_req(int level) {

	return( ([
		"taoism":10,	
	]) );
}

int query_faith_req(int skill) {
	return 3;
}

int query_sheng_ke(string skill) {

	if( skill == "ghoststrike") return 600;
	return 0;
}
