// liuyang-zhang.c

inherit SKILL;

string perform_action_file(string action)
{
        return __DIR__"liuyang-zhang/" + action;
}

mapping *action = ({
        ([      "name":                 "阳奉阴违",
                "action":               "$N使出天山六阳掌中「阳奉阴违」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
                "dodge":                0,
                "parry":                -5,
                "force":                150,
                "level":                1,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "阳春白雪",
                "action":               "$N使出一招「阳春白雪」，左掌化虚为实击向$n的$l",
                "dodge":                -5,
                "parry":                -10,
                "force":                170,
                "level":                21,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "西出阳关",
                "action":               "$N使出一招「西出阳关」，右掌穿出击向$n的$l",
                "dodge":                -10,
                "parry":                -5,
                "force":                200,
                "level":                41,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "阳谷白练",
                "action":               "$N左掌画弧，右掌推出，一招「阳谷白练」击向$n$l",
                "dodge":                -5,
                "parry":                -5,
                "force":                200,
                "level":                61,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "阳关三叠",
                "action":               "$N双掌一错，使出「阳关三叠」，对准$n的$l连续拍出三掌",
                "dodge":                0,
                "parry":                -10,
                "force":                220,
                "level":                81,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "阳歌钧天",
                "action":               "$N使出「阳歌钧天」，双掌并力推出，攻向$n的$l",
                "dodge":                -10,
                "parry":                -10,
                "attack":                20,
                "force":                300,
                "level":                101,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练天山六阳掌必须空手。\n");
        if( (int)me->query("max_force") < 500 )
                return notify_fail("你的内力太弱，无法练天山六阳掌。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="strike" || usage == "parry"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

mapping query_action(object me, object weapon)
{
        int i,level;

        level=(int)me->query_skill("liuyang-zhang",1);
        for(i=sizeof(action);i>0;i--)
                if(level>=action[i-1]["level"])
                        return action[random(i)];
        return action[0];
}

int practice_skill(object me)
{
        // 2026-04-30: unused variable commented out
        // object ob;
                
        if( (int)me->query("kee") < 30
        ||  (int)me->query("sen") < 30
        ||  (int)me->query("gin") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或精气神不够，没有办法练习天山六阳掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所学全身心地练了一遍天山六阳掌。\n");
        return 1;
}
 
void skill_improved(object me)
{
        int i,level;
                
        level=(int)me->query_skill("liuyang-zhang",1);
        for(i=0;i<sizeof(action);i++)
                if(level==action[i]["level"])
                {
                        write("你终于学会了天山六阳掌中的一招："+action[i]["name"]+"。\n");
                        return ;
                }
}

int query_property()
{
        return 16;
}

mapping *query_actions() {return action;}

int query_faith_req(int skill)  {return 300;}
//需要的内功支持怎么写?面掌暂时不需要

