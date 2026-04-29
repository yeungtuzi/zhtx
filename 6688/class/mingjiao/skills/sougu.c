//sougu.c 搜骨鹰爪功
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "\n$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招「推爪式」",
        "force" : 170,
        "dodge" : 5,
        "damage_type" : "抓伤",
        "lvl" : 0,
        "skill_name" : "推爪式"
]),
([      "action" : "\n$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招「盖爪式」双爪疾向$n脑后击下",
        "force" : 190,
        "dodge" : 20,
        "damage_type" : "抓伤",
        "lvl" : 5,
        "skill_name" : "盖爪式"
]),
([      "action" : "\n$N就地一滚，突然到了$n身前，使一招「掏爪式」，右爪直奔$n小腹",
        "force" : 215,
        "dodge" : 20,
        "damage_type" : "抓伤",
        "lvl" : 10,
        "skill_name" : "掏爪式"
]),
([      "action" : "\n$N左爪护胸，右爪凝劲后发，一招「托爪式」，缓缓托向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "damage_type" : "抓伤",
        "lvl" : 20,
        "skill_name" : "托爪式"
]),
([      "action" : "\n$N身形诡异，疾速前扑，使一招「撩爪式」，直撩$n裆部",
        "force" : 280,
        "dodge" : 25,
        "damage_type" : "抓伤",
        "lvl" : 35,
        "skill_name" : "撩爪式"
]),
([      "action" : "\n$N身形飘忽，陡然转到$n身后，一招「锁爪式」，双爪直向$n咽喉插下",
        "force" : 320,
        "dodge" : 25,
        "damage_type" : "抓伤",
        "lvl" : 60,
        "skill_name" : "锁爪式"
]),
([      "action" : "\n$N一声厉啸，身形拔起，使出「千爪式」，由半空盘旋下击，$n顿觉漫天爪影，罩向全身死穴",
        "force" : 340,
        "dodge" : 30,
        "damage_type" : "抓伤",
        "lvl" : 85,
        "skill_name" : "千爪式"
])
});

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
mapping enable_req() {

	if( this_player()->query_skill_mapped("force") == "jiuyang-shengong" )
	return( ([ 
		"force":"jiuyang-shengong",	
	]) );
	else
	return( ([ 
		"force":"moni-xinfa",	
	]) );

}
int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="hanbing-mianzhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练搜骨鹰爪功必须空手。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法学搜骨鹰爪功。\n");
        if ((int)me->query("str") < 25)
                return notify_fail("你的臂力太差，无法学搜骨鹰爪功。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object ob, object weapon)
{
        int i, level;
        level = (int)ob->query_skill("sougu", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练鹰爪功。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
//        return __DIR__"sougu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int skill,dp;
	object weapon2;
	string msg;
	
	if( !objectp( weapon2 = victim->query_temp("weapon") ) )	
		return damage_bonus;

	skill = me->query_skill("sougu",1);
	dp = (int)victim->query("combat_exp") / 100;
	if( dp < 1 )
		dp = 1;
	msg = "$N使出大力鹰爪功空手入白刃的绝招,企图强夺$n手中兵刃！\n";
	if( random(skill*skill) > dp )
	{
		if(userp(me))
			me->add("force",-50);
		msg += "$n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n";
		victim->start_busy(2);
		weapon2->move(me);
		me->start_busy(random(2));
	}
	else
	{
		msg += "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n";
		me->start_busy(2);
	}
	return msg;
}

int query_faith_req(int skill) {
	return 10+skill*10;

}
