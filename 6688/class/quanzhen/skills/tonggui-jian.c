// tonggui-jian.c 同归剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N虚步提腰，一招「同归于尽」，势如疯虎，手中$w绽出万点银光，一剑点向$n的$l",
        "force"  : 30,
        "dodge"  : -10,
        "parry"  : -10,
        "damage" : 25,
        "attack" : 5,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "紧接着$N一招「以攻为守」，浑不顾$n的攻势，一剑直劈而出",
        "force"  : 50,
        "dodge"  : -15,
        "parry"  : -20,
        "damage" : 30,
        "attack" : 20,
        "lvl" : 5,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「江天一色」，$w自上而下划出一个大弧，平平地向$n的$l刺去",
        "force"  : 70,
        "dodge"  : -15,
        "parry"  : -5,
        "damage" : 35,
        "attack" : 10,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手拿$w，一招「玉石俱焚」，集聚全身的功力向$n的$l飞速一击",
        "force"  : 85,
        "dodge"  : -10,
        "parry"  : -20,
        "damage" : 40,
        "attack" : 10,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「你死我活」，$w剑锋直出，划出无数圆圈，绵绵不断划向$n的$l",
        "force"  : 125,
        "dodge"  : -6,
        "parry"  : -7,
        "damage" : 50,
        "attack" : 5,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手捏了个剑诀，一招「虚虚实实」，右手$w挽了个斗大的剑花，逼向$n的$l",
        "force"  : 140,
        "dodge"  : -5,
        "parry"  : -5,
        "damage" : 65,
        "attack" : 15,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「柳暗花明」，身形高高跃起，$w剑尖颤动，入灵蛇一样扎向$n的$l",
        "force"  : 155,
        "dodge"  : -5,
        "parry"  : -10,
        "damage" : 70,
        "attack" :20,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
([      "action" : "$N前欺一步，一招「死而后已」，剑锋平扫，转身撩向$n的$l",
        "force"  : 210,
        "dodge"  : -15,
        "parry"  : -20,
        "damage" : 70,
        "attack" :25,
        "lvl" : 110,
        "damage_type" : "刺伤"
]),
([  "action" : "$N左手虚抱，一招「拨云见日」，$w中宫直进，刺向$n的$l",
        "force" : 220,
        "dodge" :  -10,
        "parry"  : -5,
        "attack" :30,
        "damage" : 200,
        "lvl" : 149,
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("taoism", 1) < 20)
                return notify_fail("你的道家心法不够，强练会走火入魔的。\n");
        if ((int)me->query_skill("xiantian-gong", 1) < 20)
                return notify_fail("你的先天功火候太浅。\n");
        if ((int)me->query_skill("quanzhen-jian", 1) < 40)
                return notify_fail("你的全真剑法不够. \n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tonggui-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
//        if((string)me->query("family/family_name")!="全真派")
//                return notify_fail("你练习着同归剑法，想起恩师的好处，心中一痛，就再也练不下去了。\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力不够练同归剑法。\n");
        me->receive_damage("kee", 25);
        return 1;
}
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


string perform_action_file(string action)
{
        return __DIR__"tonggui-jian/" + action;
}
mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "xiantian-gong" )
        return( ([ 
                "force":"xiantian-gong",     
        ]) );
        else
        return( ([ 
                "force":"jiuyin-shengong",   
        ]) );

}


mapping level_req(int level) {

        return( ([
                "xiantian-gong":40,     
                "taoism":20,    
        ]) );
}

int query_faith_req(int skill) {
        return 10+skill*3;
}

