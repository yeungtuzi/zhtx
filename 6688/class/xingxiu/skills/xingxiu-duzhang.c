//xingxiu-duzhang.c;星宿毒掌 

inherit SKILL;

mapping *action = ({
        ([      "name":                 "一",
                "action":               "$N脸上现出诡异的笑容，双掌拍向$n的$l",
                "dodge":                -5,
                "parry":                0,
                "attack":               15,
                "force":                40,
                "level":                1,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "二",
                "action":               "$N双掌隐隐泛出绿光，目露凶光，猛地击向$n的$l",
                "dodge":                0,
                "parry":                -5,
                "force":                60,
                "attack":               20,
                "level":                16,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "三",
                "action":               "$N双掌夹着一股腥风攻向$n的$l，令$n呼吸不畅",
                "dodge":                -10,
                "parry":                5,
                "force":                80,
                "attack":               25,
                "level":                31,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "四",
                "action":               "$N身形一晃，右手突然暴出抓向$n的$l，招式甚是阴毒",
                "dodge":                5,
                "parry":                -10,
                "attack":               30,
                "force":                100,
                "unparryable":          10,
                "undodgeable":          10,
                "level":                43,

                "damage_type":  "抓伤"
        ]),
        ([      "name":                 "五",
                "action":               "$N如鬼魅般欺至$n的身前，对着$n的头部双掌齐下",
                "dodge":                10,
                "parry":                -20,
                "attack":               40,
                "force":                120,
                "unparryable":          20,
                "undodgeable":          20,
                "level":                63,
                "damage_type":  "瘀伤"
        ]),
        ([      "name":                 "六",
                "action":               "$N一声狞笑，双掌并力退出，攻向$n的$l",
                "dodge":                -10,
                "parry":                -10,
                "attack":               50,
                "force":                150,
                "unparryable":          30,
                "undodgeable":          30,
                "level":                87,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练星宿毒掌必须空手。\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力太弱，无法练星宿毒掌。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="strike" || usage == "parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        // 2026-04-30: unused variable commented out
        // object ob;
                
        if( (int)me->query("kee") < 30
        ||  (int)me->query("sen") < 30
        ||  (int)me->query("gin") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或精气神不够，没有办法练习星宿毒掌。\n");
        me->receive_damage("kee", 20);
        me->add("force", -5);
        write("你按著所学全身心地练了一遍星宿毒掌。\n");
        return 1;
}
 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int du_lvl;
        
        if( !me->query_skill("dugong") )        return 0;
        if( !me->query_skill_mapped("dugong") ) return 0;
        if( me->query_skill_mapped("dugong") != "fushi-dugong" ) return 0;
        
        du_lvl = me->query_skill("dugong");
        if( damage_bonus + du_lvl/3 < 150 )     return 0;
        victim->receive_wound("kee", damage_bonus/3, me);
        victim->apply_condition("fushi-du", du_lvl/10);
        victim->update_condition("fushi-du");
        message_vision("$N的招式中夹着一股强劲的腥风使得$n头晕眼花！\n", me, victim);
        return 0;
}

void skill_improved(object me)
{
        return ;
}

int query_property()
{
        return 16;
}

mapping enable_req()
{
        return ([
//                "force" : "huagong-dafa",
        ]);
}

mapping level_req(int level)
{
        return ([
                "huagong-dafa" : 10,
        ]);
}

int query_faith_req()
{
        return 10;
}

mapping *query_actions() {return action;}

