// chuanyun-zhi.c -穿云指

inherit SKILL;

mapping *action = ({
([      "action" : "$N一手向$n的双眼一拂，一手却捏个剑诀，一式「千里江陵一日还」疾速击向$n的$l",
        "force" : 60,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "千里江陵一日还",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手轻扬，一手横扫，一手出一招「疑是银河落九天」，五指自上而下，向$n的胸前拂去",
        "force" : 150,
        "dodge" : 10,
        "lvl" : 5,
        "skill_name" : "疑是银河落九天",
        "damage_type" : "割伤"
]),
([      "action" : "$N身形一动，抢到$n身前，左右手同出一式「鸳鸯织就欲双飞」，向$n的$l点去",
        "force" : 150,
        "dodge" : 20,
        "lvl" : 12,
        "skill_name" : "鸳鸯织就欲双飞",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手十指上下翻飞，一式「长风几万里」，道道指风拂向$n的$l",
        "force" : 170,
        "dodge" : 30,
        "lvl" : 29,
        "skill_name" : "长风几万里",
        "damage_type" : "割伤"
]),
([      "action" : "$N一式「黄河远上白云间」，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
        "force" : 250,
        "dodge" : 30,
        "lvl" : 48,
        "skill_name" : "黄河远上白云间",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左指如剑，连续刺出，右手却一式「大漠孤烟直」，手指自下而上带起一道指风，拂向$n！",
        "force" : 280,
        "dodge" : 40,
        "lvl" : 67,
        "skill_name" : "大漠孤烟直",
        "damage_type" : "割伤"
]),
([      "action" : "$N长身跃起，双手一式「犹带昭阳日影来」，手指凌空送出，点向$n！",
        "force" : 300,
        "dodge" : 60,
        "lvl" : 96,
        "skill_name" : "犹带昭阳日影来",
        "damage_type" : "刺伤"
]),
([      "action" : "$N忽然身形一变，双手出一式「无边落木萧萧下」，手指指影竟已笼罩$n的身前身后！",
        "force" : 360,
        "dodge" : 100,
        "lvl" : 115,
        "skill_name" : "无边落木萧萧下",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「不尽长江滚滚来」，双手手指挟着锐利的指风连续点出，刺向$n的$l",
        "force" : 380,
        "dodge" : 100,
        "lvl" : 135,
        "skill_name" : "不尽长江滚滚来",
        "damage_type" : "刺伤"
]),
([      "action" : "$N忽然身形一收，眼观鼻，鼻观心，心使指，右手食指发出一道强劲无比的指力，正是一招「穿云射日」！",
        "force" : 400,
        "dodge" : 200,
        "lvl" : 149,
        "skill_name" : "穿云射日",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练穿云指必须空手。\n");
        if ((int)me->query_skill("mystforce", 1) < 30)
                return notify_fail("你的步玄心法火候不够，无法学穿云指。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练穿云指。\n");
        if ((int)me->query_skill("mystforce", 1) < (int)me->query_skill("chuanyun-zhi", 1) - 10 && (int)me->query_skill("chuanyun-zhi", 1) < 180)
                return notify_fail("你的步玄心法火候不够，无法掌握穿云指的奥秘。\n");
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
        level   = (int) me->query_skill("chuanyun-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练穿云指。\n");
        if ((int)me->query_skill("mystforce", 1) < (int)me->query_skill("chuanyun-zhi", 1) - 10 && (int)me->query_skill("mystforce", 1) < 180)
                return notify_fail("步玄心法火候不够，无法掌握穿云指的奥秘。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chuanyun-zhi/" + action;
}

string *parry_msg = ({
        "$n手指向$N$w的尖端轻轻一点，$N手中的$w顿时偏向。\n",
        "$n手指凌空一拂，锐利的指风迫的$N硬生生的收住攻势。\n",
        "$n一招「二龙戏珠」，不顾己，先攻人，$N只好收势退避。\n",
        "$n闪身出招,手指轻拂,$N只觉身上曲池穴一麻,$w竟是再也无法前进半分\n",
});
string *unarmed_parry_msg = ({
        "$n的手指化作一片指影,封住$N的全部攻势。\n",
        "$n一招「二龙戏珠」，不顾己，先攻人，$N只好收势退避。\n",
        "$n双手齐出,左手点向$N的印堂穴,右手点向$N的气海穴,$N只能撤势守身。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

mapping enable_req() {

        return( ([ 
                "force":"mystforce",    
                "dodge":"mysterrier",   
        ]) );

}

mapping level_req(int level) {

        return( ([
                "mysterrier":10,        
                "mystforce":10, 
        
        ]) );
}

int query_faith_req(int skill) {
        return 10+skill*2;
}
/*Z3A41EEC7E87CAD6D95F5F72ABE315897CA358F04H*/

