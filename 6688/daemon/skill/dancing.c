// /daemon/skill/dancing.c

inherit SKILL;

string *dodge_msg = ({
	"但是$n轻巧地一转身,避开了这一招.\n",
        "$n轻飘飘地向后退开,到了这一招的威力范围之外.\n",
	"$N忽然发现,眼前已经没有$n的踪影.\n",
	"$n借着$N攻招的力量远远地飘开,完全没有受到伤害.\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力太差了,不能练习舞蹈.\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 10;}

//string perform_action_file(string action)
//{
//        return CLASS_D("skater") + "/skating/" + action;
//}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}
