#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N双手一晃，手中的$w如一条金蛇般飞向$n的$l",
                "dodge":                20,
                "force":                20,
                "attack": 		10,
                "damage":               30,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N右手一抖，$w发出刺耳的破空声直射$n的$l",
                "dodge":                40,
                "force":                40,
                "attack": 		10,                
                "damage":               80,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手指微动，$w斜斜的飞向$n的$l",
                "dodge":                40, 
                "force":                80,
                "attack": 		10,                
                "damage":               100,                
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N力发肩肘，右手一甩，手中的$w化作一道金链射向$n的$l",
                "dodge":                20,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "attack": 		30,                
                "force" :               120,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够，没有办法练碎玉飞花。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练碎玉飞花。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="throwing" || usage == "parry") ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 500 )
                return notify_fail("你的内力或气不够，没有办法练习碎玉飞花。\n");
        me->receive_damage("kee", 30);
        return 1;
}

int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 15;
}

string perform_action_file(string action)
{
        return __DIR__"jinhua-jueji/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon;
	int	s;
	string msg;
	
	s = me->query_skill("jinhua",1);
	if( random(s) > 170 && !victim->is_busy() )
	if( (weapon = me->query_temp("weapon")) && weapon->query("id") == "Golden flower" )
	{
	        message_vision(HIY"一篷金色的花雨从$N袖中飞出，罩住$n全身。\n"NOR,me,victim);
	        if( random(me->query("combat_exp")/5000*s) > (int)victim->query("combat_exp")/80 ) {
                msg = HIR"结果$n慌乱中要穴之上中了数朵金花，顿时气血凝滞！\n" NOR;
                victim->start_busy( random(s/30)/3+1 );
		victim->add("force",-s);
        	} else {
                	msg = HIG"可是$n轻轻闪开了。\n" NOR;
		        me->start_busy(random(2));		
        	}
        	message_vision(msg, me, victim);
	}
	return 1;
}
