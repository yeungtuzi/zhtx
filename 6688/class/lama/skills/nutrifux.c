// huoyan-dao.c 火焰刀
// by masterall
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「钻木取火」，飞身急转，双掌向前平平拍向$n",
        "skill_name" : "钻木取火",
        "force" : 200,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 60,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出一招「祝融怀焰」，手掌如刀，斜斜劈向$的$l",
        "skill_name" : "祝融怀焰",
        "force" : 250,
        "attack" : 5,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 30,
        "damage" : 80,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「风火无边」，双掌一拍，一道内力自掌中攻向$n的$l", 
        "skill_name" : "风火无边",
        "force" : 300,
        "attack" : 15,
        "dodge" : 15,
        "parry" : 15,
        "lvl" : 50,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「六道轮回」，双手合十，当头劈向$n",
        "skill_name" : "六道轮回",
        "force" : 350,
        "attack" : 20,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 80,
        "damage" : 100,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「双龙吐焰」，双掌一错，两道内力交叉攻向$n的$l",
        "skill_name" : "双龙吐焰",
        "force" : 400,
        "attack" : 5,
        "dodge" : 15,
        "parry" : 20,
        "lvl" : 100,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「刀山火海」，双掌向下斜拍，顿时万千道内力从四面八方攻向$n",
        "skill_name" : "刀山火海",
        "force" : 450,
       "attack" : 25,
        "dodge" : 10,
        "parry" : 25, 
        "lvl" : 150,
        "damage" : 100,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「白佛光度」，左臂回收，右掌引内力直刺$n的$l",
        "skill_name" : "白佛光度",
        "force" : 500,
     "attack" : 15,
        "dodge" : 20,
        "parry" : 20,
        "lvl" : 199,
        "damage" : 100,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「火内莲花」，双掌微并，两臂前伸，一道内劲如排山倒海般攻向$n",
        "skill_name" : "火内莲花",
        "force" : 600,
       "attack" : 20,
        "dodge" : 20,
        "parry" : 30,
        "lvl" : 219,
        "damage" : 150,
        "unparryable" : 10,
        "damage_type" : "瘀伤",
]),
});


int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }
 

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");

        else if ((int)me->query("max_force") < 800)     //  火焰刀要有很高的内力才能学
                return notify_fail("你的内力不够。\n");
                return 1;

}

/*
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
*/

mapping query_action(object me, object weapon)
{
        int i, level;
                  level   = (int) me->query_skill("nutrifux",1); 
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够，练不了火焰刀。\n");
        me->receive_damage("kee", 50);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"nutrifux/" + action;
}

int query_sheng_ke(string skill) {
        if(skill == "liumai-shenjian") return -300;

        return 0;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int     s,t;
        string msg;

        s = me->query_skill("nutrifux",1);
        t = victim->query_skill("force");
        if( random(s) > 100 && !victim->is_busy() )
        {
                message_vision(HIR"$N脸上红光大胜，身前烟雾腾起，一条火龙般的内劲向$n直攻了过去！\n"NOR,me,victim);
                if( random(s+t) > t ) {
                msg = HIW"$n急忙运功抵御，怎奈$N的劲气逼得太猛，体内真气运转不及，"+HIC"\n只好保着灵台一点清明，硬接了$N的这一道惊涛骇浪般的掌力！\n" NOR;
   
                victim->receive_wound("kee", random(s)/8 );
                victim->add("force",-random(s)/4);
                } else {
                        msg = HIG"$n心神一动，真气护满全身，$N的攻势如泥牛入海，无影无踪。\n" NOR;
                        me->start_busy(random(2));
                }
                message_vision(msg, me, victim);
        }
        return damage_bonus;
}

int effective_level() {
        return 12;
}

