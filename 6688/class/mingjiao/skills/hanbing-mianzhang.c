// hannbing-mianzhang.c 寒冰绵掌
// pal 1997.05.26
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「大江东去」，双掌大开大合，直向$n的$l击去",
        "force" : 40,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "大江东去",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形一变，一式「黄河九曲」，双掌似曲似直，拍向$n的$l",
        "force" : 60,
        "lvl" : 10,
        "skill_name" : "黄河九曲",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「湖光山色」，左掌如微风拂面，右掌似细雨缠身，直取$n的$l",
        "force" : 90,
        "lvl" : 20,
        "skill_name" : "湖光山色",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N两掌一分，一式「曾经沧海」，隐隐发出潮声，向$n横击过去",
        "force" : 140,
        "lvl" : 30,
        "skill_name" : "曾经沧海",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形一转，使出一式「水光潋滟」，只见漫天掌影罩住了$n的全身",
        "force" : 180,
        "lvl" : 40,
        "skill_name" : "水光潋滟",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N突然身形一缓，使出一式「小雨初晴」，左掌凝重，右掌轻盈，击往$n的$l",
        "force" : 240,
        "lvl" : 50,
        "skill_name" : "小雨初晴",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「风雪江山」，双掌挟狂风暴雪之势，猛地劈向$n的$l",
        "force" : 280,
        "attack" : 5,
	"dodge" : 10,                
        "lvl" : 80,
        "skill_name" : "风雪江山",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「霜华满地」，双掌带着萧瑟的秋气，拍向$n的$l",
        "force" : 300,
        "attack" : 10,
	"dodge" : 15,                
        "lvl" : 100,
        "skill_name" : "霜华满地",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身法陡然一变，使出一式「仙乡冰舸」，掌影千变万幻，令$n无法躲闪",
        "force" : 320,
        "attack" : 10,
	"dodge" : 10,        
        "lvl" : 140,
        "skill_name" : "冰清玉洁",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N清啸一声，一式「冰霜雪雨」，双掌挥舞，如同雪花随风而转，击向$n的$l",
        "force" : 350,
        "attack" : 10,
	"dodge" : 30,
        "lvl" : 160,
        "skill_name" : "仙乡冰舸",
        "damage_type" : "瘀伤"
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
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="sougu"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练寒冰绵掌必须空手。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练寒冰绵掌。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("hanbing-mianzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 40)
                return notify_fail("你的内力不够练寒冰绵掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("hanbing-mianzhang")) > 50 )
        message_vision(HIY"$N双掌挟一股至阴至寒之气击中了$n\n"NOR,me,victim);
	victim->apply_condition("ninemoonpoison", random(me->query_skill("strike")/10) + 1 + victim->query_condition("ninemoonpoison"));
	return damage_bonus/2;
}

string perform_action_file(string action)
{
        return __DIR__"hanbing-mianzhang/" + action;
}

int query_faith_req(int skill) {
	return 10+skill*3;

}
