//  偷王八打(短兵刃)
//  touwang-bada

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N身如鬼魅，轻轻一纵，早到了$n右後侧， 手中$w打往$n脊椎尾骨处",
	"force" : 200,
	"dodge" : 100,
	"parry" : 100,
	"damage": 200,
        "lvl" : 29,
	"damage_type" : "瘀伤"
]),
([	"action": "$N低喝一声，$w一缩，飞起一脚，侧踢$n的$l",
	"attack":		100,
	"damage":		300,
	"dodge":		100,
	"parry":		100,
	"force":		300,
	"damage_type":	"瘀伤"
]),                                
([	
	"action": "$N离地跃起，飞临$n头顶上，$w雨点般往$n攻下去",
	"dodge":		300,
	"force":		400,
	"parry":		300,
	"damage":		400,
	"damage_type":	"刺伤"
]),

([      
	"action" : "$N身形一缩，着地滚入$n怀中，手中$w一昂，直点$n$l，真是捷如闪电，迅若奔雷",
        "damage" : 300,
        "dodge" : 120,
	"parry" : 120,
	"attack": 120,
        "force":  300,
        "damage_type" : "刺伤"
]),             

([  
	"action" : "$N手法一变，$w由大开大阖，变为细致柔韧，似灵蛇出洞般往$n$l攻去",
	"force" : 200,
	"parry" : 100,
	"dodge" : 100,
	"damage" :500,
        "lvl" : 159,
	"damage_type" : "刺伤"
]),

});

string *parry_msg = ({
	"$n手中$v化做狂舞的金蛇，将自己全身罩住。\n",
	"$n哈哈一笑，$v一颤下化出万点寒星，火花般弹在$N全力击来的$w上。\n",
});

string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        return 0;
}

int valid_enable(string usage)
{
	return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;
	
	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "dagger" )
		return notify_fail("你必须先找一件短兵刃才能练枪法。\n");
	if( (int)me->query("kee") < 10 )
		return notify_fail("你的内力或气不够，没有办法练习偷王八打。\n");
	me->receive_damage("kee", 5);
	return 1;
}

int attack_ratio()
{	
	return 20;
}

string perform_action_file(string action)
{
        return __DIR__"touwang-bada/" + action;
}
int npc_only() {

	return 1;
}
