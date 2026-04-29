// divine-mystsword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "暮雪三叹",
                "action":               "$N使一招「"+HIB"暮雪三叹"+NOR"」，手中$w急如骤雨般地刺向$n$l",
                "dodge":                20,
                "force":                70,
                "damage":               50,
                "parry":                20,
                "lvl":                  10,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "处子弄笛",
                "action":               "$N身形一晃，一招「"+HIG"处子弄笛"+NOR"」向$n$l刺出一剑",
                "dodge":                25,
                "force":                90,
                "damage":               80,
                "parry":                20,
                "lvl":                  50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "阳谷白练",
                "action":               "$N舞动$w，一招「"+HIW"阳谷白练"+NOR"」挟著闪闪剑光刺向$n的$l",
                "dodge":                25,
                "force":                80,
                "damage":               100,
                "parry":                25,
                "lvl":                  100,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "薰容逐电",
                "action":               "$N手中$w一个圈转，使出「"+HIC"薰容逐电"+NOR"」中锋直进刺向$n的$l",
                "dodge":                20,
                "force":                100,
                "damage":               120,
                "parry":                20,
                "attack":               5,
                "lvl":                  150,
                "damage_type":  "刺伤"
        ]),
        
        ([      "name":                 "满地落花红带雨",
                "action":               "$N曼声吟道：「"+HIR"满地落花红－带－雨！"+NOR"」，$w挽起的数十朵剑花立刻带起了一片绚丽的血雨，向$n周身撒去",
                "dodge":                20,
                "attack":               20,
                "parry":                20,
                "force":                150,
                "damage":               150,
                "undodgeable":          10,
                "damage_type":  "刺伤",
                "lvl":          221,
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("mystforce",1) < 250 )
                return notify_fail("你的步玄心法火候还不够。\n");

        if( (int)me->query("max_force") < 3000 )
                return notify_fail("你的内力不够，没有办法练步玄神剑。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("divine-mystsword",1);

        for(i = sizeof(action); i > 0; i--)
                        if(level > action[i-1]["lvl"])
                                return action[NewRandom(i, 20, level/5)];
}

/*
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
*/

int practice_skill(object me)
{
        if( me->query("force") < 100 ) return notify_fail("你的内力力不够，无法练习步玄神剑！\n");

        if( (int)me->query("kee") < 60 )
                return notify_fail("你的气不够，没有办法练习步玄神剑。\n");
        me->receive_damage("kee", 50);
        me->add("force", -20);
        write("你按著所学练了一遍步玄神剑。\n");
        return 1;
}

mapping enable_req() {

        return( ([ 
                "force":"mystforce",    
        ]) );

}

void skill_improved(object me)
{
        int i,level;
                
        level=(int)me->query_skill("divine-mystsword",1);
        for(i=0;i<sizeof(action);i++)
                if(level==action[i]["level"])
                {
                        write("你终于学会了步玄神剑中的一招："+HIG""+action[i]["name"]+""NOR+"。\n"+HIY"但同时你的内功修为也极为损耗，需要好好修养一番了！\n"NOR);
                        me->add("max_force",-2);
                        return ;
                }
}

mapping level_req(int level) {

        return( ([
                "mystforce":250, 
        ]) );
}

int query_faith_req(int skill) {
        return 3;
}

