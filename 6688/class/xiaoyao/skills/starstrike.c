// starstrike.c

inherit SKILL;

mapping *action = ({
        ([      "name":                 "月落星稀",
                "action":               "$N使一招「日落星稀」，双掌轻轻划向$n的$l",
                "dodge":                -5,
                "parry":                5,
                "force":                80,
                "level":                1,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "七星伴月",
                "action":               "$N使出「七星伴月」，身形散作七处同时向$n的$l出掌攻击",
                "dodge":                -5,
                "parry":                10,
                "force":                100,
                "level":                11,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "星罗棋布",
                "action":               "$N使出「星罗棋步」，双掌飘忽不定，令$n无可遁形",
                "dodge":                -5,
                "parry":                5,
                "force":                150,
                "level":                21,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "满天繁星",
                "action":               "$N飞身纵起，一招「满天繁星」，双掌幻化为漫天掌影罩住了$n的$l",
                "dodge":                0,
                "parry":                10,
                "force":                180,
                "level":                41,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练星河掌法必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="strike" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        int i,level;

        level=(int)me->query_skill("starstrike",1);
        for(i=sizeof(action);i>0;i--)
                if(level>=action[i-1]["level"])
                        return action[random(i)];
        return action[0];
}

int practice_skill(object me)
{
        object ob;
                
        if( (int)me->query("kee") < 20
        ||  (int)me->query("sen") < 20
        ||  (int)me->query("gin") < 20
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或精气神不够，没有办法练习星河掌法。\n");
        me->receive_damage("kee", 20);
        write("你按著所学全身心地练了一遍星河掌法。\n");
        return 1;
}

void skill_improved(object me)
{
        int i,level;
                
        level=(int)me->query_skill("starstrike",1);
        for(i=0;i<sizeof(action);i++)
                if(level==action[i]["level"])
                {
                        write("你终于学会了星河掌法中的一招："+action[i]["name"]+"。\n");
                        return ;
                }
}

int query_property()
{
        return 11;
}
mapping *query_actions() {return action;}
int query_faith_req(int skill) {return 100;}
