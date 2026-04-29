/**************************************************************************/
// $Id: tiannv-zhenfa.c,v 1.1 2000/12/14 14:41:09 cmy Exp $
/**************************************************************************/

#include <ansi.h>
inherit SKILL;

mapping *action = ({

        ([      "action":               "$N使一招「玲珑妙手」，一蓬银雨向$n洒来！",
                "damage":               80,
                "dodge":                70,
                "attack":               20,
                "damage_type":  "刺伤",
        ]),
        ([      "action":               "$N双手连挥，手中$w如「三散天花」般向$n飞来",
                "damage":               100,
                "force":                50,
                "attack":               30,
                "damage_type":  "刺伤",
        ]),
        ([      "action":               HIW"只听“叮叮”一串轻响，一蓬银雨作弧形飞来，到最后便聚到一处，\n"
                                        "凌空互击一次,四散飞激而出，力道不绝，再次击向$n前胸面目"NOR,
                "damage":               250,
                "force":                120,
                "attack":               40,
                "damage_type":  "刺伤",
        ]),

});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="throwing") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{       
        return notify_fail("天女针法不能练习.\n");
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n使出一招「花开五朵」，手中的$v射向$N的五指。\n",
        "$N面前满是暗器，却失了$n的身影。\n",
});

string *unarmed_parry_msg = ({
"$n使出一招「花开五朵」，手中的$v射向$N。\n",
"$N面前满是暗器，却失了$n的身影。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


