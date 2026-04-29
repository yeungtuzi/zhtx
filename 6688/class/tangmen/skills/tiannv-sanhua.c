// tiannv-sanhua.c 天女散花
#include <ansi.h>

inherit SKILL;
mapping *action = ({
([	"action" : "$N轻扬手臂，一式「百鸟朝凤」，向$n发出暗器",

	"dodge" : 10,
	"damage" : 20,
        "lvl" : 0,
	"damage_type" : "刺伤",
	"post_action":	(: call_other, __FILE__, "throw_weapon" :),
]),
([	"action" : "$N一式「孔雀开屏」，从袖中向$n发出一蓬暗器",

	"dodge" : 15,
	"damage" : 30,
	"force": 20,
        "lvl" : 10,
	"damage_type" : "刺伤",
	"post_action":	(: call_other, __FILE__, "throw_weapon" :),
]),
([	"action" : "$N以一式「花飘万里」，向$n的$l发出暗器",

	"dodge" : 10,
	"force": 30,
	"damage" : 40,
        "lvl" : 20,
	"damage_type" : "刺伤",
	"post_action":	(: call_other, __FILE__, "throw_weapon" :),
]),
([	"action" : "$N一式「空谷幽兰」，双手连连轻扬，将$w射向$n的$l",

	"dodge" : 10,
	"force": 35,
	"damage" : 30,
        "lvl" : 30,
	"damage_type" : "刺伤",
	"post_action":	(: call_other, __FILE__, "throw_weapon" :),
]),
([	"action" : "$N一式「莲花点点」，向$n轻扬手臂，发出$w,",

	"dodge" : 10,
	"force": 40,
	"damage" : 50,
        "lvl" : 40,
	"damage_type" : "刺伤",
	"post_action":	(: call_other, __FILE__, "throw_weapon" :),
]),
([	"action" : "$N将手中的$w以一式「飞花摘叶」，向$n射出",

	"dodge" : 10,
	"force": 50,
	"damage" : 40,
        "lvl" : 50,
	"damage_type" : "刺伤",
	"post_action":	(: call_other, __FILE__, "throw_weapon" :),
]),
([	"action" : "$N一式「天女散花」，向$n发出无数暗器",

	"dodge" : 10,
	"force": 80,
	"damage" : 50,
        "lvl" : 70,
	"damage_type" : "刺伤",
	"post_action":	(: call_other, __FILE__, "throw_weapon" :),
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
	level   = (int) me->query_skill("tiannv-sanhua",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int valid_learn(object me)

{
	if ((int)me->query_skill("throwing", 1) < 10)
		return notify_fail("你的基本暗器使用火候还不够。\n");
	return 1;
}
                                                             
int practice_skill(object me)
{
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练天女散花。\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string func)
{
        return __DIR__"tiannv-sanhua/" + func;
} 


mapping level_req(int level) {

	return( ([
		"throwing":10,	
	]) );
}

int query_faith_req(int skill) {
	return 3;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        int     s;
        string msg;

        s = me->query_skill("tiannv-sanhua",1);
        if( random(s) > 100 && !victim->is_busy() )
        if( (weapon = me->query_temp("weapon")) )
        {
                message_vision(HIY"$N双手连挥，对准$n发出"+weapon->query("name")+"。\n"NOR,me,victim);
                if( random(me->query("combat_exp")/5000*s) > (int)victim->query("combat_exp")/80 ) {
                msg = HIR"$n觉得身上一阵发麻，原来是被"+weapon->query("name")+"打中了！\n" NOR;
                victim->start_busy( (s/20)/3+1 );
                victim->apply_condition("tm_poison",victim->query_condition("tm_poison")+10);
                victim->add("force",-s);
                } else {
                        msg = HIG"可是$n轻轻闪开了。\n" NOR;
                        me->start_busy(random(2));
                }
                message_vision(msg, me, victim);
        }
        return damage_bonus;
}


mapping enable_req() {

        return( ([ 
                "force":"sunv-xinfa",        
        ]) );

}
