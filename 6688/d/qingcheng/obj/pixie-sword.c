/*pixie-sword*/
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               "$N使一招「群邪辟易」，手中的$w从一个怪异角度攻向$n的$l",
                "dodge":                50,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N使出辟邪剑法中的「钟馗抉目」，$w往前一挺,刺向$n的$l",
                "dodge":                30,
                "damage":               200,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N随便捏了个剑诀,手中$w只攻不守,向$n强攻过去",
                "dodge":                 50,
                "damage":               250,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w狂舞，一式「飞燕穿柳」对准$n的$l刺出闪电一剑",
                "dodge":                70,
                "damage":               250,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N身随剑转，手中$w从一个菲夷未闻的角度对准$n的$l攻出一招「流星赶月」",
                "dodge":                80,
                "damage":               300,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N脚踏中宫,手中$w疾如闪电，一招「辟邪无回」向$n扑了过去",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够，没有办法练辟邪剑法。\n");

        if( (string)me->query("gender")=="女性")
                return notify_fail("这不是"+RED"女人"NOR+"能练的剑法.\n");
        else if ( (string)me->query("gender")=="男性")
                return notify_fail("练辟邪剑法必须先"+RED"自宫\n"NOR);

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="dodge" || usage=="parry"; 
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("pixie-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 15 )
                return notify_fail("你的内力或气不够，没有办法练习辟邪剑法。\n");
        me->receive_damage("kee", 50);
        me->add("force", -15);
        return 0;
}
string *parry_msg = ({
        "$n使出一招「险中求胜」，手中的$v震开了$N的$w。\n",
        "$n使出「无中生有」，将$N的$w封于丈外。\n",
        "$n使出一招「穷凶极恶」，手中的$v化做漫天残照，震开了$N的$w。\n",
        "$n手中的$v一抖，一招「万元归一」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，一招「似退实进」封住了$N的攻势。\n",
        "$n反手一招「烟雨朦胧」，整个人消失在一团剑光之中。\n",
        "$n使出一招「无敌无我」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招招「穷寇还追」，迫得$N连连后退。\n",
});
string *dodge_msg = ({
	"$n身形往上一拔，一招「旱地拔葱」，一个转折落在数尺之外。\n",
	"$n身随意转，一式「点水蜻蜓」，倏地往一旁挪开了三尺，避过了这一招。 \n",
	"可是$n侧身一让，使出「扑朔迷离」，$N这一招扑了个空。 \n",
	"却见$n足不点地，一招「大江东去」，往旁窜开数尺，躲了开去。\n",
	"但是$n身形飘忽，轻轻一纵，一招「举重若轻」，避开这一击。\n"
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(parry_msg))];
        
}

int learn_bonus()
{
        return 40;
}

int black_white_ness()
{
	return -50;
}
string perform_action_file(string action)
{
      return CLASS_D("qingcheng")+"/pixie/"+action;
}
