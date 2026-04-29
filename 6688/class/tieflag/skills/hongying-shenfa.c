/**************************************************************************/
// 纵横天下-I 
// ZHTX-I Contributed Source: From 1717 
// $Id: renshu.c,v 1.1 2000/12/14 14:41:09 cmy Exp $
/**************************************************************************/
// hongying-shenfa.c

inherit SKILL;

string *dodge_msg = ({
        "$n一个转身，$N的攻击全部落空。\n",
        "$n从$N头上跃了过去，避开了所有的攻势。\n",
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
                return notify_fail("你的气或内力不够，不能练红鹰身法。\n");
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


