/**************************************************************************/
// $Id: cuiyan-shenfa.c,v 1.1 2000/12/14 14:41:09 cmy Exp $
/**************************************************************************/
// cuiyan-shenfa.c

inherit SKILL;

string *dodge_msg = ({
        "$n一个侧身，$N的攻击全部落空。\n",
        "$n腾空而起，避开了所有的攻势。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练翠燕身法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 10;}

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


