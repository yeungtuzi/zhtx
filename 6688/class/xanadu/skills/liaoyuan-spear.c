//  燎原枪法
//  liaoyuan-spear

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N的眼神忽地变得无比锐利．一声狂啸，$w化作一条怒龙，绞击而上。这一枪不属\n"
		   "燎原枪法内的任何一式．纯属因时制宜．随手拈来。但又含蕴着燎原枪法的一招奇招",
	"force" : 200,
	"dodge" : 100,
	"parry" : 100,
	"damage": 200,
        "lvl" : 29,
	"damage_type" : "刺伤"
]),
([	"action": "$N枪势一收再放，笼罩的范围竟扩大了一倍，由起手式「无定击」转入第二式「雨暴风狂」，枪影吞吐间，每一个人都似是被攻击的目标",
	"attack":		100,
	"damage":		300,
	"dodge":		100,
	"parry":		100,
	"force":		300,
	"damage_type":	"刺伤"
]),                                
([	
	"action": "$N枪影收回，由左腰眼处往後缩回去，到了$N背後。有枪变无枪。从左腰眼退"
		  "回去的$w，魔术变幻般从右腰眼处吐出来，直标$n$l！正是燎原枪法绝技 － 无枪式",
	"dodge":		300,
	"force":		400,
	"parry":		300,
	"damage":		400,
	"damage_type":	"刺伤"
]),

([      
	"action" : "$N傲然单足柱地，另一脚脚背却架在独立地上那脚的腿膝後，$w以奇异的波浪轨迹，绥缓横扫。\n"
		   "就像烈火烧过草原。地上的尘屑树叶，随着枪势带起的劲气，卷飞而起",
        "damage" : 300,
        "dodge" : 120,
	"parry" : 120,
	"attack": 120,
        "force":  300,
        "damage_type" : "刺伤"
]),             

([  
	"action" : "$N使出燎原百击里叁十击的起手式「无定击」，手中$w飘忽不定，如同狂风骤雨卷向$n$l",
	"force" : 200,
	"parry" : 100,
	"dodge" : 100,
	"damage" :500,
        "lvl" : 159,
	"damage_type" : "刺伤"
]),

});

string *parry_msg = ({
	"$n扛在肩头的$v一动，万道红影在全身周围扇子般 起，隔断了$N的攻势。\n",
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
	return usage=="spear" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;
	
	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "spear" )
		return notify_fail("你必须先找一条长枪才能练枪法。\n");
	if( (int)me->query("kee") < 10 )
		return notify_fail("你的内力或气不够，没有办法练习燎原枪法。\n");
	me->receive_damage("kee", 5);
	return 1;
}

int attack_ratio()
{	
	return 20;
}

int npc_only() {

	return 1;
}
