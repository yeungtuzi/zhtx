 // qishang-quan.c -七伤拳
// yeung
// 1998/07/21
// all rights reserved.

#include <ansi.h>

inherit SKILL;

string  *damage_msg = ({
        HIR"你感到肩头云门穴有些轻微隐痛。\n"NOR,
        HIR"你感到上臂青灵穴时时麻痒难当。\n"NOR,
        HIR"你腿上无里穴一阵酸痛。\n"NOR,
});

mapping *action = ({
([      "action" : "$N气凝如山，一式「摧心伤肺」，双拳蓄势而发，威不可当",
        "force" : 260,
        "dodge" : 10,
        "attack": 20,
        "lvl"   : 0,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形凝重，劲发腰背，缓缓向$n挥出一拳",
        "force" : 280,
        "dodge" : 15,
        "attack": 25,
        "lvl"   : 20,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪",
        "force" : 320,
        "dodge" : 20,
        "attack": 25,
        "lvl" : 40,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N长啸一声，向前踏出一步，双拳中宫直进，一式「七者皆伤」，骤然击向$n的前胸",
        "force" : 400,
        "dodge" : 25,
        "attack": 30,
        "lvl"   : 100,
        "unparryable": 10,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使出一招「乾坤尽赤」，突然暴喝一声，虎目圆睁，浑身骨节喀喀做响，双拳向$n连续击出",
        "force" : 500,
        "dodge" : 30,
        "attack": 40,
        "lvl"   : 120,
        "unparryable": 20,
        "damage_type" : "瘀伤"
]),
});

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
mapping level_req(int level) {

        return( ([
                "jiuyang-shengong":200,  
        ]) );
}
int valid_combine(string combo) { return combo=="ill-quan"; }

mapping enable_req() {

        return( ([ 
                "force":"jiuyang-shengong",        
        ]) );
}
int valid_enable(string usage)
{ 
        return  usage=="cuff" || usage=="parry"|| usage=="hand"; 
}

int valid_learn(object me)
{
        if ( me->query("gender") != "男性" || me->query_str() < 45 )
                return notify_fail("七伤拳刚猛霸道，你的体质不适合修习这门功夫。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练七伤拳必须空手。\n");
        if ((int)me->query("max_force") < 3000)
                return notify_fail("你的内力太弱，无法练七伤拳。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
//        level   = (int) me->query_skill("qishang-quan",1);
//        for(i = sizeof(action); i > 0; i--)
//                if(level > action[i-1]["lvl"])
                        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练七伤拳。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qishang-quan/" + action;
}

//void skill_improved(object me)
//{
//        if( (int)me->query("max_force") < (int)me->query_skill("qishang-quan", 1)*20 ) 
//        {
//              me->add("marks/qishang-hurt",1);
//              tell_object(me, damage_msg[random(3)]);
//              if( (int)me->query_skill("qishang-quan", 1) > (int)me->query("spi")*5 )             //  
//              {
//                        tell_object(me, HIR"由于你内功修为不到就强练七伤拳，损伤了你的五脏六腑和//奇经八脉！\n"NOR);
//                        me->unconcious();
// //                       me->delete_skill("qishang-quan");
//                        me->set("max_force",me->query("max_force")/2 + //random(me->query("max_force"))/2);
//                        me->set("con",(int)me->query("con")/2);
//                        me->delete("qishang-hurt");                  
//              }
//        }
//}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( me->query("force") < 200 ) return damage_bonus/4;   
        if( me->query("id") == "long xiang" && victim->query("id") != "long xiang") {
                victim->receive_wound("sen",victim->query("max_sen")/3);
                victim->receive_wound("gin",victim->query("max_gin")/3);
                victim->receive_wound("kee",victim->query("max_kee")/2);
                   }
        if( !random(3) )
        {
                message_vision(HIR"七道或刚或柔若断若连的真气随$N的招式侵入了$n的奇经八脉！\n"NOR,me,victim);
                victim->receive_wound("gin",me->query_skill("cuff")/7,me);
                victim->receive_wound("sen",me->query_skill("cuff")/7,me);
                victim->receive_wound("kee",me->query_skill("cuff")/2,me);
        }
        return damage_bonus;
}

int query_faith_req(int skill) {
        return 10+skill*2;

}
