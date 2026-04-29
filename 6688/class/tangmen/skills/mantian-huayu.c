// mantian-huayu.c 漫天花雨
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N轻扬手臂，一式「星光灿烂」，向$n发出暗器",

        "dodge" : 10,
        "force": 20,
        "attack" : 10,
        "damage" : 10,
        "lvl" : 0,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action" : "$N一式「霞光万道」，向$n的$l射出暗器",

        "dodge" : 15,
        "force": 30,
        "attack" : 10,
        "damage" : 20,
        "lvl" : 10,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action" : "$N使出一式「月隐星移」，向$n发出无数暗器",

        "dodge" : 10,
        "force": 20,
        "attack" : 15,
        "damage" : 30,
        "lvl" : 20,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action" : "只见$N挥动手臂，向$n的$l发出$w",

        "dodge" : 11,
        "force": 30,
        "attack" : 15,
        "damage" : 40,
        "lvl" : 30,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action" : "$N手臂连挥，一式「繁星点点」，将手中的暗器向$n射出",

        "dodge" : 15,
        "force": 20,
        "attack" : 20,
        "damage" : 50,
        "lvl" : 40,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action" : "$N将手中的暗器以一式「月落星稀」发出，射向$n的$l",

        "dodge" : 10,
        "force": 30,
        "attack" : 20,
        "damage" : 60,
        "lvl" : 50,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action" : "$N一式「漫天花雨」，向$n发出无数暗器",

        "dodge" : 20,
        "attack" : 30,
        "force": 140,
        "damage" : 170,
        "undodgeable" : 20,
        "lvl" : 70,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
});

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) 
        {
                if( weapon->query("no_decrease") )      
                        weapon->add_amount(1);
                if( (int)weapon->query_amount()==1 ) 
                {
                        weapon->unequip();
                        tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n\n");
                }
                weapon->add_amount(-1);

        }
}

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("mantian-huayu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int valid_learn(object me)
{
        if ((int)me->query_skill("throwing", 1) < 10)
                return notify_fail("你的基本暗器手法火候还不够。\n");
        return 1;
}
                                                             
int practice_skill(object me)
{
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练漫天花雨。\n");
        me->receive_damage("kee", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"mantian-huayu/" + action;
} 

int query_faith_req(int skill) {
        return 4;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        int     s;
        string msg;

        s = me->query_skill("mantian-huayu",1);
        if( random(s) > 100 && !victim->is_busy() )
        if( (weapon = me->query_temp("weapon")) )
        {
                message_vision(HIY"$N双手连挥，对准$n发出"+weapon->query("name")+"。\n"NOR,me,victim);
                if( random(me->query("combat_exp")/5000*s) > (int)victim->query("combat_exp")/80 ) {
                msg = HIR"$n觉得身上一阵发麻，原来是被"+weapon->query("name")+"打中了！\n" NOR;
                victim->start_busy( s/30 + 1 );
                victim->add("force",-s);
                } else {
                        msg = HIG"可是$n轻轻闪开了。\n" NOR;
                        me->start_busy(random(2));
                }
                message_vision(msg, me, victim);
        }
        return damage_bonus;
}

/*
mapping enable_req() {

        return( ([ 
                "force":"tangmen-xinfa",        
        ]) );

}
*/
mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "tangmen-xinfa" )
        return( ([ 
                "force":"tangmen-xinfa",     
        ]) );
        else if( this_player()->query_skill_mapped("force") == "yin-gong" )
        return( ([ 
                "force":"yin-gong",   
        ]) );
        else
        return( ([ 
                "force":"kuihua-shengong",   
        ]) );

}


