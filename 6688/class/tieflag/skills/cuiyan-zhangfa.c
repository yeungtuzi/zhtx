/**************************************************************************/
// $Id: hongying-zhangfa.c,v 1.1 2000/12/14 14:41:09 cmy Exp $
/**************************************************************************/

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N使出一招「燕低飞」，左掌虚幌，右掌穿出击向$n的$l",
                "attack":                10,
                "parry":                20,
                "force":                150,
                "lvl":                  20,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N使出一招「燕瘦环肥」，右掌化爪，左掌化虚为实击向$n的$l",
                "parry":                10,
                "attack":               40,
                "force":                 170,
                "lvl":                   100,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N双掌一错，使出「春寒料峭」，对准$n的$l连续拍出",
                "parry":                -10,
                "attack":               60,
                "damage":               100,
                "force":                260,
                "lvl":                  150,
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N左掌立于胸前，右掌推出，一招「欲走还留」击向$n$l",
                "damage":                100,
                "parry":                100,
                "attack":               100,
                "force":                400,
                "lvl":                  199,
                "damage_type":  "瘀伤",
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练翠燕掌法必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

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
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 8;}
 
string *parry_msg = ({
        "$n双掌微合，使出一招「燕瘦环肥」，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n略一转身，一招「欲走还留」拍向$N拿着$w的手。\n",
});

string *unarmed_parry_msg = ({
        "$n步走阴阳，一招「功敌自救」虚空拍出三掌，逼得$N撤招自保。\n",
        "$n施展出「燕低飞」，轻描淡写的化解了$N的攻势。\n",
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
        return 50;
}
int practice_bonus()
{
        return 25;
}
int black_white_ness()
{
        return 100;
}



