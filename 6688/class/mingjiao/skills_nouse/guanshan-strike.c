// 关山掌法
// yeung. 1998.7.18

inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N双掌一错，一招“明月出天山”幻出漫天掌影拢向$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌纷飞，一招“苍茫云海间”直取$n的$l",
                "dodge":                10,
                "parry":                30,
                "damage":                30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N暴喝一声，双掌连环推出，一招“长风几万里”强劲的掌风直扑$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出“吹度玉门关”，完全将$n的$l笼罩在双掌之下",
                "dodge":                10,
                "parry":                30,
                "damage":                60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N内气上提，全身拔起，一招“汉下白登道”，双掌凌空拍下",
                "dodge":                70,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N化掌为刀，一招“胡窥青海湾”，左右掌分砍$n的两处要害",
                "dodge":                20,
                "parry":                30,
                "damage":                40,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N提气游走，一招“高楼当此夜”，森森掌风无孔不入般地击向$n的$l",
                "parry":                40,
                "force":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N闭目垂手，一式 ”叹息未应闲”，双掌轻飘飘地击向$n的$l",
                "parry":                40,
                "force":                320,
		"damage" :		150,
                "damage_type":  "内伤"
        ]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{ 
        object me;
        
        me = this_player();
        if( (me->query_skill_mapped("force") != "jiuyang-shengong") && (me->query_skill_mapped("force") != "moni-xinfa"))
	{
	       write("关山神掌只能配合九阳神功或者摩尼圣火心法使用。\n");
	       return 0;
	}

	return usage=="strike" || (usage=="parry")|| (usage=="unarmed"); 
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练关山神掌必须空手。\n");

        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
 
string *parry_msg = ({
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string query_parry_msg(object weapon)
{
                return parry_msg[random(sizeof(parry_msg))];
}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
        return __DIR__"guanshan-strike/" + action;
}

