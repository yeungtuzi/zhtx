
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N双手一晃，手中的$w如一条金蛇般飞向$n的$l",
                "dodge":                20,
                "force":		20,
                "damage":               30,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N右手一抖，$w发出刺耳的破空声直射$n的$l",
                "dodge":                40,
                "force":		40,
                "damage":               80,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手指微动，$w斜斜的飞向$n的$l",
                "dodge":                40, 
                "force":		80,
                "damage":               100,                
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N力发肩肘，右手一甩，手中的$w化作一道金链射向$n的$l",
                "dodge":                20,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
		"force"	:		120,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

//        if( (me->query_skill_mapped("force") != "jiuyang-shengong") && (me->query_skill_mapped("force") != "moni-xinfa"))
//	       return notify_fail("金花绝技只能配合九阳神功或者摩尼圣火心法使用。\n");

        if( (int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够，没有办法练金花绝技。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练金花绝技。\n");

        return 1;
}

int valid_enable(string usage)
{
//        object me;
        
//        me = this_player();
//        if( (me->query_skill_mapped("force") != "jiuyang-shengong") && (me->query_skill_mapped("force") != "moni-xinfa"))
//	{
//	       write("金花绝技只能配合九阳神功或者摩尼圣火心法使用。\n");
//	       return 0;
//	}
        return usage=="throwing";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 500 )
                return notify_fail("你的内力或气不够，没有办法练习金花绝技。\n");
        me->receive_damage("kee", 30);
        write("你按著所学练了一遍金花绝技。\n");
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
