/**************************************************************************/
// $Id: tie_makeing.c,v 1.1 2000/12/14 14:41:09 cmy Exp $
/**************************************************************************/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([     "action" :               "$N从腰间掏出一块似铁非铁的东西，很快便做成一柄"MAG"长剑"NOR",趁$n讶异间向$n的$l刺来，\n"
                                        "转眼又恢复成原样，放回$N的腰间", 
                "attack":               10,
                "force":                10,
                "damage":               30,
                "lvl":                  0,
                "damage_type":  "刺伤",
        ]),
        ([      "action":               "$N从腰间掏出一块似铁非铁的东西，很快便做成一把"CYN"弯刀"NOR"，迎头向$n砍来，\n"
                                        "转眼又恢复成原样，放回$N的腰间",
                "attack":               10,
                "parry":                20,
                "force":                20,
                "damage":               40,
                "lvl":                  20,
                "damage_type":  "割伤",
        ]),
        ([      "action":               "$N从腰间掏出一块似铁非铁的东西，很快便做成一根"BLK"长鞭"NOR"，从$n的后面卷来，\n"
                                        "转眼又恢复成原样，放回$N的腰间",
                "parry":                10,
                "attack":               30,
                "force":                30,
                "damage":               50,
                "lvl":                   40,
                "damage_type":  "鞭伤",
        ]),
        ([      "action":               "$N从腰间掏出一块似铁非铁的东西，很快便做成一杆"HIR"长枪"NOR"，向$n点来，\n"
                                        "转眼又恢复成原样，放回$N的腰间",
                "parry":                5,
                "attack":               40,
                "force":                40,
                "damage":               70,
                "lvl":                   60,
                "undodgeable":          5,
                "damage_type":  "口伤",
        ]),        
        ([      "action":               "$N从腰间掏出一块似铁非铁的东西，很快便做成一杆"YEL"长杖"NOR"，向$n的$l狠狠一捅，\n"
                                        "转眼又恢复成原样，放回$N的腰间",
                "parry":                -10,
                "dodge":                -80,
                "attack":               70,
                "damage":               90,
                "force":                60,
                "lvl":                  80,
                "undodgeable":          10,
                "damage_type":  "刺伤",
        ]),
        ([      "action":               "$N从腰间掏出一块似铁非铁的东西，很快便做成一把"HIC"锤子"NOR"，向$n的$l用力一□，\n"
                                        "转眼又恢复成原样，放回$N的腰间",
                "parry":                -10,
                "dodge":                -80,
                "attack":               70,
                "damage":               100,
                "force":                80,
                "lvl":                  100,
                "unparryable":          10,
                 "damage_type":  "挫伤",
        ]),
        ([      "action":               "$N从腰间掏出一块似铁非铁的东西，很快便做成一把"HIW"斧头"NOR"，向$n的$l劈来，\n"
                                        "转眼又恢复成原样，放回$N的腰间",
                "parry":                -10,
                "dodge":                -100,
                "attack":               80,
                "damage":               150,
                "force":                160,
                "lvl":                  150,
                "unparryable":          20,
                "damage_type":  "挫伤",
        ]),

});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练鬼斧神工必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
       int i,level;
       level = (int) me->query_skill("tie_makeing",1);
         for(i=sizeof(action);i>0;i--)
           if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 20 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 40);
        me->add("force", -15);
        return 1;
}
int effective_level() { return 14;}
 
string *parry_msg = ({
        "$n双掌微合，使出一招「鹬蚌相争」，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n略一转身，一招「欲走还留」拍向$N拿着$w的手。\n",
});

string *unarmed_parry_msg = ({
        "$n步走阴阳，一招「苏三起解」虚空拍出三掌，逼得$N撤招自保。\n",
        "$n施展出「花为煤」，轻描淡写的化解了$N的攻势。\n",
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
        return __DIR__"tie_makeing/"  + action;
}

int help(object me)
{
        write(@HELP

        鬼斧神工是夜帝独创功夫的一门空手兵刃功夫，等级足够时可以制作
        炸药攻击群体(perform unarmed.make_bomb),
        配合music可以弹高山流水来伤敌(perform unarmed.make_music).

HELP
        );
        return 1;
}


