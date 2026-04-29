// /daemon/skill/flysteps.c
// 天河步法
// by mscat

inherit SKILL;

string *dodge_msg = ({
	"$n一招「逆风千里」大踏步抢到$N身后。\n",
	"$n展臂伏身,堪堪躲过$N的一击。\n",
	"$n使出一招「一飞冲天」,如大鸟般凌空跃过$N头顶,令得$N的攻势完全落空。\n",
	"$n使出一招「凭虚而行」,借$N来招的力量向一旁滑开。\n",
	"$n一招「繁星似尘」,急速移动的身形化作数个幻影,$N完全不知道该攻击哪一个。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练习天河步法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}



int practice_skill(object me)
{
	if( (int)me->query("kee") < 3000
	||	(int)me->query("force") < 5 )
		return notify_fail("你的气或内力不够，不能练习天河步法。\n");
	me->receive_damage("kee", 3000);
	me->add("force", -5);
	return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 40;
}
int query_faith_req(int skill) {
        return 100*skill+10000;
}
