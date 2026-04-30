//夺命连环三仙剑
#include <ansi.h>

inherit SKILL;

void post_action1(object me,object victim,object weapon,int damage)
{
	
	if( damage > 0 )
	{
		if( objectp(me) )
		{
			message_vision(GRN"$N一招使完，"+weapon->query("name")+"收势不及，圈转了回来，从自己的左肩对穿而过！\n"NOR,me);
			me->receive_wound("kee",damage/2);
			COMBAT_D->report_status(me,me,1);
		}
		if( objectp(victim) )
		{
			victim->receive_wound("kee",damage,me);
		}
	}
}

void post_action2(object me,object victim,object weapon,int damage)
{
	if( damage > 0 )
	{
		if( objectp(me) )
		{
			message_vision(HIW"$N牙关紧咬，潜运真气，强自支撑。\n"NOR,me);			
			me->receive_wound("kee",damage/2);
			COMBAT_D->report_status(me,me,1);
		}
		if( objectp(victim) )
		{
			victim->receive_wound("kee",damage,me);
		}
	}
}

void post_action3(object me,object victim,object weapon,int damage)
{
	if( damage > 0 )
	{
		if( objectp(me) )
		{
			message_vision(MAG"$N面色苍白，摇摇欲倒，腹部鲜血不住流出，显然自己也受伤不轻。\n"NOR,me);
			me->receive_wound("kee",damage*2/3);
			COMBAT_D->report_status(me,me,1);
		}
		if( objectp(victim) )
		{
			victim->receive_wound("kee",damage*2,me);
		}
	}
}

mapping *action = ({
([	
	"name" : "天地同寿",
	"action" : "$n一招攻向$N,$N不顾敌招来势，反而转身退入$n怀中，\n$w顺势后刺，竟是要先行洞穿自己腹部，再行杀敌！\n其势之险，$n已闪无可闪，避无可避，正是武当派的一式「天地同寿」",
	"force" : 300,
	"damage" : 300,
	"unparryable" : 200,
	"undodgeable" : 200,
	"damage_type" : "刺伤",
	"post_action" : (: call_other, __FILE__, "post_action3" :),
]),
([	
	"name" : "人鬼同途",
	"action" : "$N一招「人鬼同途」，手中$w斜围，身子向$n电射而至，$w反而跟在身后！\n$n见$N来势如此凶悍，决计无法抵挡，大惊之下，忽然间全身冰凉，\n骇怖达于几点，就此呆立不动！$N将身子抵在$n兵刃之上，$w趁势挺出",
	"force" : 300,
	"damage" : 280,
	"unparryable" : 200,
	"undodgeable" : 200,
	"damage_type" : "刺伤",
	"post_action" : (: call_other, __FILE__, "post_action2" :),
]),
([	
	"name" : "玉碎昆岗",
	"action" : "$N银牙紧咬，使出一式昆仑派杀招「玉碎昆岗」，\n连人带$w直扑入$n怀中，$w紧接着刺出，去势凌厉之极。\n$n别说躲避，便是招架也已有所不及",
	"force" : 280,
	"damage" : 300,
	"unparryable" : 200,
	"undodgeable" : 200,
	"damage_type" : "刺伤",
	"post_action" : (: call_other, __FILE__, "post_action1" :),
]),

});

int valid_learn(object me)
{
        // 2026-04-30: unused variable commented out
        // object ob;

        if( (int)me->query_skill("sword",1) < 150 )
                return notify_fail("你的剑术修为不够，学不了这三大杀招。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") ;
}

mapping query_action(object me, object weapon)
{
	int index;
        index = (int) me->query_temp("marks/lightingsword") + 1;
        if( index >= sizeof(action) ) index = 0;
        me->set_temp("marks/lightingsword",index);
        return action[index];
}

int practice_skill(object me)
{
        return notify_fail("这门功夫不能练！\n");
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
