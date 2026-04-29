inherit SKILL;
mapping *action = ({
([      "action" : "$N一招「花径暗香流」，右手一扬，无数细针脱手而出，无声无响地飞向$N。",
        "force" : 10,
        "dodge" : 5,
        "damage": 130,
        "lvl" : 0,
        "weapon":"玉蜂针",
        "damage_type" : "刺伤"
]),
([      "action" : "$N抓出一把细针，一记「垂杨千万缕」,只见空中冲出无数银线，击向$n的全
身各处要穴。",
        "force" : 10,
        "dodge" : 10,
        "damage": 150,
        "lvl" : 8,
        "weapon":"玉蜂针",
        "damage_type" : "刺伤"
]),
([      "action" : "$N欺身向前，左手微向后扬，右手一挥，一招「呵手梅妆薄」，数根细针以七种劲道射向$n。",
        "force" : 30,
        "dodge" : 15,
        "damage": 170,
        "lvl" : 60,
        "weapon":"玉蜂针",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手五指微挥，一招「无绪倦寻芳」，十数根针成一条直线，射向$n。",
        "force" : 30,
        "dodge" : 20,
        "damage": 190,
        "lvl" : 100,
        "weapon":"玉蜂针",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手连挥，无数暗器漫天盖地地卷向$n,好一招「纤云锁朱楼」。",
        "force" : 20,
        "dodge" : 20,
        "damage": 220,
        "lvl" : 100,
        "weapon":"玉蜂针",
        "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }

int valid_learn(object me)
{
      
        if ((int)me->query_skill("yunu-xinfa", 1) < 20)
                return notify_fail("你的玉女心法火候不够，无法学织女神针。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练织女神针。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("zhinv-zhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练织女神针。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        return 1;
}
string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});
string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
        