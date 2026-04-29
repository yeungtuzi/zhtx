//天山折梅手

inherit SKILL;

mapping *action = ({
        ([      "name":                 "踏雪寻梅",
                "action":               "$N使出一招「踏雪寻梅」��身形绕着$n转了个半弧，突然双手直探$n的$l",
                "parry":                5,
                "dodge":                5,
                "force":                170,
                "level":                1,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "梅香袭人",
                "action":               "$N向前踏上半步��一招「梅香袭人」，双手一送趁势直取$n的$l",
                "parry":                10,
                "dodge":                10,
                "force":                190,
                "level":                11,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "寒梅吐蕊",
                "action":               "$N双手连挥��幻化为数个手影攻向$n的$l，正是一招「寒梅吐蕊」",
                "parry":                10,
                "dodge":                10,
                "force":                200,
                "level":                21,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "映雪红梅",
                "action":               "$N使出一招「映雪红梅」，凝神不动，双手却暗指$n的$l",
                "parry":                10,
                "dodge":                10,
                "force":                220,
                "level":                31,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "梅花弄影",      
                "action":               "$N左手护胸��右手向上一探一招「梅影疏斜」��拿向$n的$l，姿态美妙",
                "parry":                10,
                "dodge":                10,
                "force":                240,
                "level":                41,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "梅掩黄昏",      
                "action":               "$N使出天山折梅手中一招「梅掩黄昏」��双手轻轻一带，攻向$n的$l",
                "parry":                15,
                "dodge":                15,
                "force":                250,
                "level":                51,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "老梅虬枝",
                "action":               "$N一招「老梅虬枝」��双手分别从一个出人意料的角度向$n的$l捞去",
                "parry":                15,
                "dodge":                15,
                "force":                280,
                "level":                61,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "梅凋无声",
                "action":               "$N使出「梅凋无声」��双手默默地掠过$n的$l",
                "parry":                20,
                "dodge":                20,
                "force":                200,
                "level":                71,
                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "吹梅笛怨",
                "action":               "$N一招「吹梅笛怨」，双手纷飞，令$n眼花缭乱",
                "parry":                20,
                "dodge":                20,
                "force":                320,
                "level":                81,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "梅花三弄",
                "action":               "$N双手一扬，一招「梅花三弄」，先后三道手影冲向$n的$l",
                "parry":                25,
                "dodge":                25,
                "force":                420,
                "level":                91,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "砌下落梅如雪乱",
                "action":               "$N身形陡然拔起，一招「砌下落梅如雪乱」，扑天盖地的掌影裹住了$n的全身",
                "parry":                30,
                "dodge":                30,
                "attack":               20,
                "force":                450,
                "level":                101,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练天山折梅手必须空手。\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力太弱��无法练天山折梅手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="hand" || usage == "parry"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

mapping query_action(object me, object weapon)
{
        int i,level;

        level=(int)me->query_skill("zhemei-shou",1);
        for(i=sizeof(action);i>0;i--)
                if(level>=action[i-1]["level"])
                        return action[random(i)];
        return action[0];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||  (int)me->query("sen") < 30
        ||  (int)me->query("gin") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或精气神不够，没有办法练习天山折梅手。\n");
        me->receive_damage("kee", 30);
        me->add("force", 0);
        write("你按著所学全身心地练了一遍天山折梅手。\n");
        return 1;
}

void skill_improved(object me)
{
        int i,level;
                
        level=(int)me->query_skill("zhemei-shou",1);
        for(i=0;i<sizeof(action);i++)
                if(level==action[i]["level"])
                {
                        write("你终于学会了天山折梅手中的一招："+action[i]["name"]+"。\n");
                        return ;
                }
}

string perform_action_file(string action)
{
         return __DIR__"zhemei-shou/" + action;
}

int query_property()
{
        return 11;
}
mapping *query_actions() {return action;}
int query_faith_req(int skill)  {return 100;}
//内功支持不好写

