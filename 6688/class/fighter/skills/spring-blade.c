// spring-blade.c

inherit SKILL;



mapping *action = ({
        ([      "action":               "$N使一招「春风拂人醉」，手中$w轻飘飘地向$n的$l斩去！",
                "attack":               30,
                "damage":               300,
                "dodge":                -20,
                "parry":                -10,
                "force":                300,
                "undodgeable":          20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N金刃劈风，$w随著一招「远山伴人痴」由下而上撩往$n的$l",
                "damage":               80,
                "attack":               15,
                "parry":                -10,
                "dodge":                -5,
                "force":                100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身形一转，一招「飞花逐人香」$w刀光不定，斩向$n的$l",
                "damage":               80,
                "parry":                -10,
                "attack":               20,
                "dodge":                5,
                "force":                90,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N舞动$w，一招「柳叶随人笑」迅捷无伦地劈向$n的$l",
                "dodge":                60,
                "parry":                -10,
                "attack":               20,
                "damage":               20,
                "force":                80,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w一晃，一招「倩影惹人怜」往$n的$l斜斜砍出一刀",
                "damage":               100,
                "parry":                -10,
                "attack":               15,
                "force":                100,
                "dodge":                -5,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N提刀过肩，蓄劲发力，一招「芦雪碎人影」直劈$n$l",
                "damage":               110,
                "parry":                -10,
                "attack":               20,
                "force":                70,
                "dodge":                0,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N移步侧身，使一招「彩蝶灼人衣」刀光霍霍斩向$n的$l",
                "damage":               120,
                "parry":                -10,
                "force":                70,
                "attack":               20,
                "dodge":                0,
                "damage_type":  "割伤"
        ]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{

        if( me->query("skill_mark/spring-blade") && random(100) > 35 )
        {
                return action[0];
        }
        else
                return action[random(sizeof(action)-1)+1];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀，才能练刀法。\n");

        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
        return 1;
}

int attack_ratio() {
        if( this_player()->query("skill_mark/spring-blade") )
                return 60;
        else 
                return 0;
}

/*
mapping enable_req() {

        return( ([ 
                "force":"celestial",    
                "dodge":"pyrobat-steps",        
        ]) );

}
*/
mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "celestial" )
        return( ([ 
                "force":"celestial",     
        ]) );
        else
        return( ([ 
                "force":"taohua-force",   
        ]) );

}


mapping level_req(int level) {

        return( ([
                "celestial":60, 
                "pyrobat-steps":80,
        ]) );
}

int query_faith_req(int skill) {
        return skill*8+20;
}

int query_sheng_ke(string skill)
{
        if (skill == "taiji-jian") return -800;
        return 0;
}
string perform_action_file(string action)
{
        return __DIR__"spring-blade/" + action;
}
