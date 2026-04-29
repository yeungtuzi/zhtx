// taiji-jian.c 太极剑
// by yeung
//modified by masterall

inherit SKILL;

mapping *action = ({
([      "action" : "$N$w一举，目视剑尖，心无旁鹜，跟着含胸拔背、沉肩坠肘,\n一招「起手式」,$w圈转,刺向$n$l",
        "force" : 60,
        "parry" : 30,
        "damage" : 50,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左足踏上，剑交左手，一招「三环套月」，$w虚虚实实，\n以左手剑攻敌，剑尖上光芒闪烁，嗤嗤嗤的发出轻微响声",
        "force" : 70,
        "parry" : 20,
        "damage" : 50,
        "dodge" : 10,
        "lvl" : 9,
        "damage_type" : "刺伤"
]),
([      "action" : "$N跟着便是「大魁星」、「燕子抄水」，$w在空中划成大圈，\n右手剑诀戳出，竟似也发出嗤嗤微声。",
        "force" : 80,
        "parry" : 25,
        "damage" : 50,
        "dodge" : 10,   
        "lvl" : 19,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑法吞吐开合、阴阳动静，一式「指南针」,手中$w圆转如意,斜撩$n$l",
        "force" : 90,
        "parry" : 30,
        "dodge" : 15,   
        "damage" : 60,
        "lvl" : 59,
        "damage_type" : "刺伤"
]),
([      "action" : "$N$w收起,一式「如封似闭」，双手虚抱成圆，接着$w以弧形刺出",
        "force" : 100,
        "parry" : 35,
        "attack": 20,
        "dodge" : 15,   
        "damage" : 80,
        "lvl" : 99,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形凝重如山.手中$w却是轻灵如羽,意在剑先、绵绵不绝,一招\n「进道若退」,$w指向$n$l",
        "force" : 120,
       "attack": 20,
        "parry" : 30,
        "damage" : 100,
        "dodge" : 15,   
        "lvl" : 129,
        "damage_type" : "刺伤"
]),
([      "action" : "$N心中一片空灵，$w每发一招，便似放出一条细丝，要去将$n裹\n在中央,突然，一招「明道若昧」，$w奇兵突出，逼向$n的$l",
        "force" : 140,
        "parry" : 35,
        "attack": 20,
        "dodge" : 20,
        "damage" : 100,
        "lvl" : 159,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出一招「道隐无名」，左手剑诀，虚画了几个圈子，以意驭剑，\n手中$w千变万化，无穷无尽，虚虚实实，轻若无物地刺向$n$l",
        "force" : 180,
        "parry" : 35,
        "attack": 25,
        "dodge" : 30,   
        "damage" : 120,
        "lvl" : 199,
        "damage_type" : "刺伤"
]),

});
mapping action2 =
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
        "force" : 200,
        "parry" : 30,
        "attack": 30,
        "damage" : 160,
        "unparryable": 15,
        "lvl" : 219,
        "damage_type" : "刺伤"
]);



int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 20)
                return notify_fail("你的太极神功火候太浅。\n");
    if ((int)me->query_skill("taiji-shengong", 1) < (int)me->query_skill("taiji-jian", 1) - 20 && (int)me->query_skill("taiji-jian", 1) < 201)
        return notify_fail("你的太极神功火候不够，无法领悟太极剑形神合一，用意不用力，圆转贯串，滔滔不绝的招术.\n");
        if ((int)me->query_skill("taiji-quan", 1) < 20)
                return notify_fail("你的太极拳火候太浅。\n");
/*        if ((int)me->query_skill("taiji-jian",1)>200 
                && (int)me->query_skill("taiji-jian",1)>(int)me->query_skill("taiji-shengong",1))
                return notify_fail("你的太极神功火候不够，无法领悟太极剑形神合一，用意不用力，圆转贯串，滔滔不绝的招术.\n");*/
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("taiji-jian",1);
        if( me->query("skill_mark/taiji-jian") && random(level) > random(398))
        {
                return action2;
        }
        else{
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
            }
}



int effective_level() 
{
        return 13;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 70)
                return notify_fail("你的体力不够练太极剑法。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < (int)me->query_skill("taiji-jian", 1) - 20 && (int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("你的太极神功火候不够，无法领悟太极剑形神合一，用意不用力，圆转贯串，滔滔不绝的招术.\n");
        me->receive_damage("kee", 60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"taiji-jian/" + action;
}

string *parry_msg = ({
        "$n左手剑诀斜引，$v横过，画个半圆，将$N$w带出尺许之外。\n",
        "$n$v平搭在$N$w之上，劲力传出，$N手中$w登时一沉。\n",
        "$n回剑圈转，拍的一声，$N手中的$w一震，不住颤动，发出嗡嗡之声，良久不绝。\n ",
        "$n手中$v一侧，以己之钝，挡敌之无锋，将$w粘出外围。\n",
        "$n手中$v划出大大小小、正反斜直各种各样的圆圈,$N不由自主连转了几个圈子。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int query_sheng_ke(string skill)
{
        if (skill == "spring-blade") return 300;
        if (skill == "snowwhip") return 200;
        return 0;
}

mapping enable_req() {

        return( ([ 
                "force":"taiji-shengong",       
        ]) );

}

mapping level_req(int level) {

        return( ([
                "taiji-shengong":20,    
        ]) );
}

int query_faith_req(int skill) {
        return 10+skill*6;
}

