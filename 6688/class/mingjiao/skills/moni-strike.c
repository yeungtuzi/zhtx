inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N突然转身，绕至$n背后，双掌连环推出，一股强劲的掌风直扑$n的$l",
                "force":                120,
                "attack":                10,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N化掌为刀，右掌发出淡淡的金色光芒，一式“掌刀”，直砍$n的$l",
                "attack":                10,
                "force":		140,
                "weapon": 		"右掌",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N提气游走，身形盘旋不定，森森掌风如同水银泄地般击向$n的$l",
                "attack":                10,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N左掌不停地划了几个圈子，扰得$n眼花缭乱，突然间，右手从万千掌影中穿出，直扑$n的$l",
                "attack":                25,
                "force":                350,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练摩尼连环掌必须空手。\n");
        if( (int)me->query_skill("moni-xinfa", 1) < 10)
                return notify_fail("你的摩尼圣火心法火候不足，无法练摩尼连环掌。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed" || usage=="strike" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
        return 1;
}
 
string *parry_msg = ({
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n施展出摩尼连环掌，轻描淡写的化解了$N的攻势。\n",
        "$n使出「粘」字诀，双掌一划，引偏了$N的攻势。\n",
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
	return 5;
}

int black_white_ness()
{
	return -10;
}

int effective_level() {
       return 11;
}

mapping enable_req() {
        return( ([ 
            "force":"moni-xinfa",     
        ]) );
}
