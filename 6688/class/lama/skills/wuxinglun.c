// wuxinglun.c 五行轮法

#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「凿金势」，抡起手中的$w向$n的$l砸去  ",
        "skill_name" : "凿金势",
        "force" : 80,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 50,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「伐木势」，双肩一沉，舞动手中$w向$n的$l横扫  ",
        "skill_name" : "伐木势",
        "force" : 60,
        "dodge" : -20,
        "parry" : 20,
        "lvl" : 8,
        "damage" : 60,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「挑水势」，就地一滚，手中自下而上撩向$n的$l  ",
        "skill_name" : "挑水势",
        "force" : 50,
        "dodge" : -20,
        "parry" : 10,
        "lvl" : 16,
        "damage" : 70,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「烈火势」，身形起伏之际$w扫向$n的$l  ",
        "skill_name" : "烈火势",
        "force" : 90,
        "dodge" : 5,
        "parry" : 15,
        "lvl" : 89,
        "attack" : 5,
        "damage" : 85,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「入地势」，$w如离弦之箭般直捣$n的$l  ",
        "skill_name" : "入地势",
        "force" : 180,
        "dodge" : -10,
        "parry" : 10,
        "attack" : 5,
        "lvl" : 129,
        "damage" : 90,
        "damage_type" : "挫伤",
]),
([      "action" : "$N跃入半空，使一招「捉月势」，高举$w敲向$n的$l  ",
        "skill_name" : "捉月势",
        "force" : 220,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 159,
        "attack" : 10,
        "damage" : 100,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「破竹势」，斜举手中$w击向$n的$l  ",
        "skill_name" : "破竹势",
        "force" : 260,
        "dodge" : -15,
        "parry" : 15,
        "lvl" : 179,
        "attack" : 15,
        "damage" : 120,
        "damage_type" : "挫伤",
]),
([      "action" : HIY"$N提一口真气，使出「圆满势」，$w"+HIY"风驰电掣般扫向$n"+HIY"的头部  "NOR,
        "skill_name" : "圆满势",
        "force" : 280,
        "dodge" : 20,
        "parry" : 25,
        "attack" : 25,
        "lvl" : 199,
        "damage" : 240,
        "unparryable": 25,
        "damage_type" : "挫伤",
]),
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"|| usage == "staff"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 13*me->query_skill("banruo",1))
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("banruo", 1) >= 20)
                return 1;
        else if ((int)me->query_skill("banruo", 1) < 20)
                return notify_fail("你的龙象般若功火候太浅。\n");
//        if( me->query_skill("dodge") )
//                return notify_fail("五行轮不能与轻功一同使用。\n");
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
        level   = (int) me->query_skill("wuxinglun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够,练不了五行轮法。\n");
        me->receive_damage("kee", 30);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object victim_w;
        victim_w = victim->query_temp("weapon");

        if (victim->query_temp("weapon") ||
            victim->query_temp("secondary_weapon"))
        {
                if( random(me->query_skill("wuxinglun", 1)) < 100 )
                return HIW "一阵兵刃相撞的声音过后，对方兵器居然完好无损。\n" NOR;
                if( victim->query_temp("apply/damage") < 
                random(me->query_skill("wuxinglun", 1)+victim->query_temp("apply/damage") ) )
                {
                        victim_w->unequip();
                        victim_w->reset_action();
                        victim_w->move(environment(victim));
                        victim_w->set("name", victim_w->query("name") + "的碎片");
                        victim_w->set("value", 0);
                        victim_w->set("weapon_prop", 0);
                        victim_w->set("long", "一堆破碎物事，好象是兵器碎片。\n");
                        return HIB "你听到「叮当」一声兵刃破碎的声音，兵器碎片溅了一地！\n" NOR;
                }
        }
}
string perform_action_file(string action)
{
    return __DIR__"wuxinglun/" + action;
}

mapping enable_req() {
        return( ([
//            "force":"banruo",
        ]) );
}

