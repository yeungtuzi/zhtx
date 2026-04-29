/*pine-sword*/

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N使一招「苍松迎客」，手中的$w化为一道剑光刺向$n的$l",
                "dodge":                30,
		"force":		30,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N使出松风剑法中的「傲雪青松」，$w化作一条青龙霍霍斩向$n的$l",
                "dodge":                30,
		"force":		40,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N一招「松声万壑」，手中$w旋出点点光芒,向$n罩下去",
                "dodge":                25,
		"force":		50,
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w往侧面一送，一式「万流同踪」对准$n的$l就是一剑",
                "dodge":                30,
		"force":		60,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N凝神专一，手中$w似快似慢的对准$n的$l攻出一招「独上高峰」",
                "dodge":                20,
		"force":		70,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N的$w凌空一立，一招「孤松渡月」刺向$n的$l",
                "dodge":                35,
		"force":		80,
                "damage":               80,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练松风剑法。\n");

        

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习松风剑法。\n");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        write("你按著所学练了一遍松风剑法。\n");
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("qingcheng") + "/pine-sword/" + action;
}
string *parry_msg = ({
        "$n使出一招「独步云程」，用手中的$v直刺$N的胸腹。\n",
        "$n左脚踏前一步，一招「顾盼又怜」，手中的$v从侧面飘向$N之必救。\n",
        "$n手中的$v一抖，挽出一朵朵剑花，一招「天网恢恢」，撒向$N的全身。\n",
        "$n微退一步，手中的$v划出一条光弧，一招「惟我独尊」，将$N的全身围住。\n",
});

string *unarmed_parry_msg = ({
"$n使出一招「似愚实智」，用手中的$v急砍$N。\n",
"$n左脚踏前踏，一招「围魏救赵」，手中的$v挥向$N之必救。\n",
"$n手中的$v一抖，一招「中流砥柱」，奔向$N。\n",
"$n手中的$v划出一招「舍生忘死」，将$N的全身围住。\n",
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
        return 30;
}
int practice_bonus()
{
        return 20;
}
int black_white_ness()
{
        return -50;
}

int attack_ratio() {
	return(18);
}

mapping enable_req() {

	return( ([ 
		"force":"qingcheng-force",	
		"dodge":"qingcheng-steps",	
	]) );

}

mapping level_req(int level) {

	return( ([
		"qingcheng-force":10,	
		"qingcheng-steps":10,	
	]) );
}

int query_faith_req(int skill) {
	return 10+skill*2;
}
