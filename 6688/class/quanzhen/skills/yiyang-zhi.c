// yiyang-zhi 一阳指
// Made by ysg (1997.10.19)

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N侧身抬臂，右手食指划圈，缓缓推出，一式「普渡众生」摁向$n的$l",
	"force"  : 260,
	"lvl" : 20,
	"skill_name" : "普渡众生",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「童子拜佛」，双手合十，一股锐利无俦的内力，凌虚向$n的$l涌去",
	"force"  : 240,
	"lvl" : 45,
	"skill_name" : "童子拜佛",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「无我无相」，左手食指指尖向天，指端射出一缕罡气，穿过$n的$l",
	"force"  : 220,
	"lvl" : 65,
	"skill_name" : "无我无相",
        "damage_type" : "刺伤"
]),
([	"action" : "$N满眼慈悲，一式「四大皆空」，右手食指对着对着$n的眉心遥遥摁去，$n不知\n"
			"为何，只觉万般皆空，竟然忘了躲开。",
	"force"  : 480,
	"undodgeable" : 30,
	"lvl" : 82,
	"attack" : 20,
	"parry" : 10,
	"skill_name" : "四大皆空",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="anran-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 50)
		return notify_fail("你的先天功火候不够，无法学一阳指。\n");
	if ((int)me->query("max_force") < 400)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
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
	level   = (int) me->query_skill("yiyang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 100)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 40)
		return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("kee", 90);
	me->add("force", -30);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yiyang-zhi/" + action;
}

/*
mapping enable_req() {

	return( ([ 
		"force":"xiantian-gong",	
	]) );

}
*/
mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "xiantian-gong" )
        return( ([ 
                "force":"xiantian-gong",     
        ]) );
        else
        return( ([ 
                "force":"jiuyin-shengong",   
        ]) );

}


mapping level_req(int level) {

	return( ([
		"xiantian-gong":50,	
	]) );
}

int query_faith_req(int skill) {
	return 600+skill*3;
}
