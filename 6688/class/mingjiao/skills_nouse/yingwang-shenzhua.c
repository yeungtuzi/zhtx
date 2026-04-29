// yingzhua-gong.c -鹰王神爪

inherit SKILL;

mapping *action = ({
([	"action" : "$N双臂一振，使一式「鹰王展翅」，一拔身，双爪分别袭向$n左右腋空门",
	"force" : 100,
        "dodge" : 15,
        "parry" : 15,
	"damage": 15,
	"lvl" : 0,
	"skills_name" : "迎风振翼",
        "damage_type" : "内伤"
]),
([	"action" : "$N端立不动，一式「飞鹰献爪」，双爪摆出奇异的姿势，$n不由自主落入双爪的笼罩范围之内",
	"force" : 180,
        "dodge" : 20,
        "parry" : 20,
	"damage": 15,
	"lvl" : 40,
	"skills_name" : "飞鹰献爪",
        "damage_type" : "内伤"
]),
([	"action" : "$N伏地滑行，一式「翼蔽天下」，上手袭向膻中大穴，下手反抓$n的裆部",
	"force" : 250,
        "dodge" : 25,
        "parry" : 25,
	"damage": 20,
	"lvl" : 80,
	"skills_name" : "翼蔽天下",
        "damage_type" : "内伤"
]),
([	"action" : "$N左右手掌爪齐施，一式「鹰击长空」，爪端射出丝丝劲气，迅疾无比地击向$n",
	"force" : 300,
        "dodge" : 25,
        "parry" : 25,
	"damage": 25,
	"lvl" : 120,
	"skills_name" : "鹰击长空",
        "damage_type" : "内伤"
]),
([	"action" : "$N腾空高飞三丈，一式「鹰翔九天」，身法灵动如意，爪影纷飞，罩住$n",
	"force" : 470,
        "dodge" : 40,
        "parry" : 40,
	"damage": 30,
	"lvl" : 150,
	"skills_name" : "鹰翔九天",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

// int valid_combine(string combo) { return combo=="fengyun-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练鹰王神爪必须空手。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练鹰王神爪。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("yingwang-shenzhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练鹰爪功。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

