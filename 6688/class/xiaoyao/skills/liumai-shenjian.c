/*六脉神剑: 少泽、少冲、少商、中冲、关冲、商阳*/

#include <ansi.h>
#include <combat.h>


inherit SKILL;

mapping *action = ({
        ([      "name":                 "少泽剑",
                "action":               "$N左手小指点出，伴着嗤地一声轻响，一招「"+HIG"少泽剑"NOR+"」刺向$n的$l",
                "attack":               30,
                "dodge":                30,
                "parry":                30,
                "force":                300,
               "damage":                100,
                "weapon":               "少泽剑气",
                "lvl":                  50,
                "damage_type":  "刺伤",
                "post_action":  (: call_other,__FILE__,"hitweapon" :),
        ]),
        ([      "name":                 "少冲剑",
                "action":               "$N右手小指一伸，一道凌厉无比的无形剑气破空直奔$n的$l，好一招精妙的「"+HIG"少冲剑"NOR+"」",
                "attack":               30,
                "dodge":                30,
                "parry":                35,
                "force":                400,
               "damage":                200,
                "weapon":               "少冲剑气",
                "lvl":                  100,
                "damage_type":  "刺伤",
                "post_action":  (: call_other,__FILE__,"hitweapon" :),
        ]),
        ([      "name":                 "关冲剑",
                "action":               "$N无名指一指，「嗤──」，一招「"+HIG"关冲剑"NOR+"」对着$n的$l的刺去",
                "attack":               35,
                "dodge":                25,
                "parry":                30,
                "force":                450,
               "damage":                150,
                "lvl":                  150,
                "weapon":               "关冲剑气",
                "damage_type":  "刺伤",
                "post_action":  (: call_other,__FILE__,"hitweapon" :),
        ]),
        ([      "name":                 "中冲剑",
                "action":               "$N中指一弹，「"+HIG"中冲剑"NOR+"」剑气挟石破天惊之势奔向$n的$l",
                "attack":               30,
                "dodge":                20,
                "parry":                20,
                "force":                520,
               "damage":                100,
                "lvl":                  200,
                "unparryable":          20,
                "weapon":               "中冲剑气",
                "damage_type":  "刺伤",
                "post_action":  (: call_other,__FILE__,"hitweapon" :),
        ]),
        ([      "name":                 "商阳剑",
                "action":               "$N食指凌空一指，正是一招轻灵迅捷的「"+HIG"商阳剑"NOR+"」，刺向$n的$l",
                "attack":               30,
                "dodge":                30,
                "parry":                30,
                "force":                630,
               "damage":                150,
                "lvl":                  220,
                "undodgeable":          20,
                "weapon":               "商阳剑气",
                "damage_type":  "刺伤",
                "post_action":  (: call_other,__FILE__,"hitweapon" :),
        ]),
        ([      "name":                 "少商剑",
                "action":
"$N大拇指一按，一招「"+HIG+"少商剑"NOR+"」，剑法大开大阖，气势宏伟，刺向$n的$l",
                "attack":               40,
                "dodge":                35,
                "parry":                35,
                "force":                800,
               "damage":                250,
                "lvl":                  249,
                "undodgeable":          20,
                "unparryable":          20,
                "weapon":               "少商剑气",
                "damage_type":  "刺伤",
                "post_action":  (: call_other,__FILE__,"hitweapon" :),
        ]),
});


int valid_learn(object me)
{
        if(me->query("max_force") < 1000)
                return notify_fail("你的内力太低了，不能学六脉神剑．\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练六脉神剑必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int attack_ratio() {
        return 60;
}

int counter_attack_ratio() {
        return 50;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||  (int)me->query("sen") < 30
        ||  (int)me->query("gin") < 30
        ||  (int)me->query("force") < 110 )
                return notify_fail("你的内力或精气神不够，没有办法练习六脉神剑。\n");
        me->receive_damage("kee", 30);
        me->add("force", -80);
        return 1;
}


mapping enable_req() {

        return( ([ 
                "force":"beiming-shengong",       
        ]) );

}

void skill_improved(object me)
{
        int i,level;
                
        level=(int)me->query_skill("liumai-shenjian",1);
        for(i=0;i<sizeof(action);i++)
                if(level==action[i]["level"])
                {
                        write("你终于学会了六脉神剑中的一招："+HIG""+action[i]["name"]+""NOR+"。\n");
                        return ;
                }
}

string perform_action_file(string action)
{
        return __DIR__"liumai-shenjian/" + action;
}

void hitweapon(object me,object victim,object weapon,int damage)
{
        object ob;
        int wap,wdp;

        if(damage==RESULT_PARRY && (ob=victim->query_temp("weapon")))
        {
                wap=(int)me->query("force")/50+(int)me->query_str();
                wdp=(int)ob->weight()/500+(int)ob->query("rigidity")+(int)victim->query_str();
                wap=random(wap);
                if(wap>2*wdp)
                {
                        message_vision(HIW"只听得铛的一声，$N手中的"+ob->name()+
"已被$n的六脉神剑的剑气震飞！\n"NOR,victim,me);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                }
                else if(wap>wdp)
                {
                        message_vision(HIW"只听见铛铛铛数声，$N手中的"+ob->name()+
"以被六脉神剑的剑气击成数截！\n"NOR,victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name","断掉的"+ob->query("name"));
                        ob->set("value",(int)ob->query("value")/10);
                        ob->set("weapon_prop",0);
                        victim->reset_action();
                }
                else 
                        message_vision(HIW"$N手中的"+ob->name()+
"被六脉神剑的剑气一击之下，只觉右臂一阵酸麻．\n"NOR,victim);
        }
}

