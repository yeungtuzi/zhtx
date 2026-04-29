                                                  //  essence-sword
//  浣花萃玉剑

inherit SKILL;

mapping *action = ({
//emei
([      "action" : "$N一招峨嵋剑法「万流归宗」，手中$w化出的重重剑影合而为一，一气呵成地攻向$n的$l",
        "force" : 160,
        "dodge" : 10,
        "attack": 15,
        "parry" : 15,
        "damage" : 80,
        "lvl" : 29,
        "damage_type" : "刺伤"
]),
//dei-sword
([      "action": "$N使出蝶恋花剑中的「草色烟光残照里」，剑光向残照般洒向$n的$l",
        "dodge":                20,
        "attack":               20,
        "force":                80,
        "damage":               100,
        "lvl" :                 49,
        "damage_type":  "割伤"
]),
//mo-jian-jue
([      "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「置酒长安道」刺向$n的$l",
        "force" : 260,
        "dodge" : 5,
        "damage": 55,
        "attack": 20,
        "lvl" : 60,
        "skill_name" : "置酒长安道",
        "damage_type":  "刺伤"
]),
//piexie-sword
([      "action":"$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n",
        "force" : 80,
        "dodge" : 10,
        "attack":25,
        "damage": 100,
        "lvl" : 80,
        "skill_name" : "腰枝猛摆",
        "damage_type":  "刺伤"
]), 
//damo-jian
([      "action":"$N合掌跌坐，一式「禅心顿自明」，$w自怀中跃出，如疾电般射向$n的胸口",
        "force" : 180,
        "dodge" : 5,
        "attack" : 20,
        "damage": 60,
        "lvl" : 90,
        "skill_name" : "禅心顿自明",
        "damage_type":  "刺伤"
]),          
//quanzhen-jian
([  
        "action": "$N反手一挥，一招「曲院风荷」，剑尖斜指，手中$w从一个意想不到的方向直刺$n的咽喉。",
        "force" :150,
        "parry" :10,
        "attack":15,
        "dodge" :25,
        "damage":90,
        "lvl"   :110,
        "zhaoshi" : "「曲院风荷」",
        "damage_type" : "刺伤",
]), 
//six-chaos-sword
([      "name":                 "群魔乱舞",
        "action":               "$N使一招「群魔乱舞」，手中$w狂风骤雨般地向$n的$l连攻数剑",
        "dodge":                5,
        "parry":                20,
        "attack":               20,
        "damage":               150,
        "force":                70,
        "undodgeable":          15,
        "lvl" :                 120,
        "damage_type":  "刺伤"
]),           
//yunv-suxinjian
([      "action" : "$N手中$w轻扬，飘身而进，姿态飘飘若仙，剑锋向$n的下盘连点数点，却是一招「小园艺菊」.",
        "damage" : 140,
        "dodge" : 50,
        "attack": 20,
        "force": 180,
        "lvl" : 139,
        "damage_type" : "刺伤"
]),  
//taiji-jian
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
        "force" : 180,
        "parry" : 30,
        "attack": 30,
        "damage" : 100,
        "unparryable":          20,
        "lvl" : 159,
        "damage_type" : "刺伤"
]),
//spring-blade
([      "action":               "$N化剑为刀，剑锋一转，使一招「春风拂人醉」，手中$w轻飘飘地向$n的$l斩去！",
        "attack":               20,
        "damage":               300,
        "dodge":                -20,
        "parry":                -10,
        "force":                300,
        "unparryable":          15,
        "lvl" : 220,
        "damage_type":  "割伤"
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

int valid_learn(object me)
{
        if ( me->query("gender") != "女性"  )
                return notify_fail("浣花淬玉剑走的是阴柔的路子，你的体质不适合修习这门功夫。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("moni-xinfa", 1) < 150)
                return notify_fail("你的摩尼心法火候太浅。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}
/*
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
*/
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("essence-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}


string perform_action_file(string action)
{
        return __DIR__"essence-sword/" + action;
}

int practice_skill(object me)
{
        object ob;
        
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if( (int)me->query("kee") < 50 )
                return notify_fail("你的内力或气不够，没有办法练习摩尼剑法。\n");
        me->receive_damage("kee", 40);
        return 1;
}


mapping level_req(int level) {

        return( ([
                "moni-xinfa":150,  
        ]) );
}

mapping enable_req() {

        return( ([ 
                "force":"moni-xinfa",        
        ]) );

}

int query_faith_req(int skill) {
        return skill*6+3;
}

int query_ally(string skill,int amount)
{
        if( skill=="shenghuo-shengong" ) return 250;
        return 0;
}

