// /daemon/skill/cloudhand.c
// 摩云掌法
//
// by mscat

inherit SKILL;

mapping *action = ({
	([
	"action":"$N轻舒长臂,一招「翻手为云」,拍向$n的$l",
	"dodge":10,
	"parry":10,
	"force":20,
	"damage":10,
	"damage_type":	"瘀伤"
	]),
        ([
	"action":"$N长吸一口气,双手连挥,掌影重重罩向$n",
        "dodge"	:-50,
        "parry"	:-30,
        "force"	:100,
	"damage":60,
        "damage_type":  "瘀伤"
        ]),
        ([
	"action":"$N右掌忽化为爪,一招「覆手作雨」,在$n的$l上重重地划了一道",
	"dodge"	:30,
        "parry"	:-30,
        "force"	:160,
	"damage":100,
        "damage_type":  "抓伤"
        ]),
        ([
        "action":"$N左掌上托,右手握拳,一招「举袂蔽日」,直捣向$n的$l",
        "dodge" :10,
        "parry" :10,
        "force" :180,
	"damage":150,
        "damage_type":  "挫伤"
        ]),
	([
	"action":"$N左手一引,右手一招「揭竿成旗」抓向$n的$l",
	"dodge" :-30,
	"parry" :50,
	"force" :100,
	"damage":200,
	"damage_type":  "抓伤"
	])
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练摩云掌法必须空手。\n");
/*
	if( me->query_skill("fireforce", 1)*2 <
		me->query_skill("cloudhand", 1))
return notify_fail("你的烈火神功太差了,无法继续领悟摩云掌法的诀窍.\n");
*/
	return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry"|| usage=="strike";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
/*        if( me->query_skill("fireforce", 1)*2 <
                me->query_skill("cloudhand", 1))
return notify_fail("你的烈火神功太差了,无法继续领悟摩云掌法的诀窍.\n");
*/
        if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 35);
        me->add("force", -5);
	return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n一招「壁立千仞」，双手齐出，将$N手中的$w挡在外门。\n",
	"$n五指如钩,探手抓向$N持$w的手腕，险些将$w夺下! $N只好撤招。\n",
	"$n以掌作剑,戳向$N前胸要害,迫得$N不得不先行闪避。\n",
	"$n使出一招「风扬万年」，一股强横的内劲硬生生将$N的$w逼回。\n"
});

string *unarmed_parry_msg = ({
	"$n一招「壁立千仞」，双手齐出，将$N的攻势挡在外门。\n",
	"$n以掌作剑,戳向$N前胸要害,迫得$N不得不先行闪避。\n",
	"$n使出一招「风扬万年」，一股强横的内劲硬生生将$N逼回。\n"
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

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
	return 80;
}

