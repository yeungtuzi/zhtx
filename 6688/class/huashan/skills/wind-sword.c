// wind-sword.c 狂风快剑
#include <combat.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N提起手中$w，向$n的$l刺去，剑式绝快无伦，仿佛若闪电一般",
        "force":  10,
        "parry" : -10,
        "damage" :50,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w一引，$w带着一股凛冽的寒气，直刺向$n的$l。",
        "force" : 20,
        "parry" : -10,
        "damage" :60,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "只见$N手腕一抖，手中$w突然幻化出四道寒光，包围了$n的身周方圆数尺之地。",
        "force" : 20,
        "parry" : -15,
        "damage" : 70,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一剑快似一剑，映出千道闪光，带着缕缕风声，直刺向$n的$l。",
        "force" : 10,
        "parry" : -20,
	"attack": 15,
        "damage" : 100,
        "lvl" : 30,
        "damage_type" : "砍伤"
]),
([      "action" : "只见$N出剑越来越快，招式越来越急，随着$w激起的风声也越来越响，$n正看的眼花，\n$N突然在千朵剑花之中刺出一剑。",
        "force" : 10,
        "parry" : -20,
        "damage" : 110,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N仰天一声清啸，斜行而前，长剑横削直击，迅捷无比，将$n的退路团团围住。",
        "force" : 30,
        "damage" : 120,
	"undodgeable": 20,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
});

mapping op_action =
([      
	"action" : "$N不待敌人变招，紧接着便是一式”天外玉龙“，长剑指向敌人喉头，剑尖青芒隐隐！\n",
        "force" : 50,
        "parry" : 30,
	"attack": 20,
	"undodgeable": 20,
        "damage" : 120,
        "damage_type" : "刺伤"
]);



int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

/*int valid_learn(object me)
{
        if ((int)me->query_skill("huashan-neigong",1)<50)
           return notify_fail("你的内功修为不够无法学习狂风快剑\n");
        if ((int)me->query_skill("huashan-jianfa",1)<100)
           return notify_fail("你的剑术修为不够，无法学习狂风快剑\n");      
        if ((int)me->query("max_force") < 100)
           return notify_fail("你的内力不够。\n");
        return 1;
}
*/


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


mapping query_action(object me, object weapon)
{
        int i, level;
	object victim;
	
        level = (int) me->query_skill("wind-sword", 1);
	if( level > 120 && me->query_temp("skill_mark/wind-sword") )
	{
        //狂风快剑的perform生效
        		me->set_temp("skill_mark/wind-sword-counting",1);
                	me->clean_up_enemy();
                	victim = me->select_opponent();
                	if( objectp(victim) )  
			{
				message_vision(op_action["action"],me,victim);
                		COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_SELFATTACK,op_action);
			}
        }
	
        	for(i = sizeof(action); i > 0; i--)
        	if(level > action[i-1]["lvl"])
              		return action[NewRandom(i, 20, level/5)];
	
}

int practice_skill(object me)
{
	int kee;
	kee = 30*(1+me->query("betrayer"));

       if( (int)me->query("kee") < kee + 20)
        return notify_fail("你的气不够，没有办法练习狂风快剑。\n");
        me->receive_damage("kee", kee);
        return 1;
 
}


int attack_ratio(string skill)
{
	if( skill == "dugu-jiujian" )
		return 10;
	return 200;
}

/*
mapping enable_req() {
	if( this_player()->query_skill_mapped("dodge") == "yan-shuangfei" )
		return( ([ 
			"dodge":"yan-shuangfei",
		]) );
	else
		return( ([ 
			"dodge":"yanshuangfei",
		]) );
}
*/

mapping level_req(int level) {

	return( ([
		"sword":10,	
		"huashan-shenfa":10,	
	]) );
}

int query_faith_req(int skill) {
	return 10*skill+100;
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/skills/wind-sword/" + action;
}

