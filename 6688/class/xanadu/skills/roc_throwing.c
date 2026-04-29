#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
		"朦胧之中，一道寒光如急电般射向$n",
                "dodge":                100,
		"parry":		100,
                "damage":               200,
		"force" :		250,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        return 0;
}

int valid_enable(string usage)
{
        return (usage=="throwing") ;
}

mapping query_action(object me, object weapon)
{
        return action[0];
}

int practice_skill(object me)
{
	return 0;
}

int npc_only() {

	return 1;
}
