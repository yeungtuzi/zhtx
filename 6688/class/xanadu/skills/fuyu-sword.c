//  fuyu-sword
//  覆雨剑法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : CYN"一阵啸声轻响，$N被一团银芒完全遮盖，而后，银芒迅速爆开，\n周围满是光点，将$n全身尽数裹入银芒之中"NOR,
	"force" : 500,
	"dodge" : 100,
	"parry" : 100,
	"damage": 500,
        "lvl" : 29,
	"damage_type" : "刺伤"
]),
([	"action": GRN"$N手中$w化出千道寒芒，万点光雨，一时天地间尽是剑锋和激动的气旋，\n啸啸生风。一连串密集的兵刃交击声音，同时响起"NOR,
	"attack":		100,
	"damage":		600,
	"dodge":		100,
	"parry":		100,
	"force":		600,
	"damage_type":	"割伤"
]),                                
([	
	"action": MAG"一阵低啸有若龙吟，室内顿生漫漫剑雨。名震天下的「覆雨剑法」，\n全力展开。生死立决。成功失败，都变化於刹那之间"NOR,
	"dodge":		100,
	"force":		700,
	"parry":		100,
	"attack":		100,
	"damage":		700,
	"damage_type":	"刺伤"
]),

([      
	"action" :  BLU"「锵！」 $w离鞘而出，先由怀中暴涌出一团光雨，接着雨点扩散，\n瞬那间$n身前身後尽是光点，令人难以相信这只是由一把剑变化出来的视象"NOR,
        "damage" : 800,
        "dodge" : 120,
	"parry" : 120,
	"attack": 120,
        "force":  800,
        "damage_type" : "刺伤"
]),             

([      
	"action" :  RED"$N手中$w化作一团反映着天上电光的银白芒点，流星追月般画过虚空，循一道包涵了天地至理的弧线，往$n投去"NOR,
        "damage" : 900,
        "dodge" : 120,
	"parry" : 120,
	"attack": 120,
        "force":  900,
        "damage_type" : "刺伤"
]),             

([  
	"action" : YEL"$N举剑直击，便在同时，千百道电光激打而下，在$n头顶爆起了远近可见，\n震破了虚空，强烈至使人睁不开眼来的庞大电光火团"NOR, 
	"force" : 1000,
	"parry" : 300,
	"dodge" : 300,
	"attack": 150,
	"damage" :1000,
        "lvl" : 159,
	"damage_type" : "刺伤"
]),

});

string *parry_msg = ({
	"一阵似乎微不可闻的低吟，在$n手中响起，连$w强劲的破风声，亦不能掩盖。\n$v离鞘而出，像蛟龙出海，大鹏展翅，先是一团光芒，光芒蓦然爆开，化作一天光雨，漫天遍地迎向$N的$w。\n",
	"一连串声音响起，正像骤雨打在风铃上，每一点光雨，硬碰上$N的$w。\n",
	"$n卓立原地不动，但无论$N怎样攻击，从$n手上爆开激射的剑雨，总能硬把攻势封挡。\n",
	"$n手中$v爆起漫天光雨，像一片光网般把$N的$w完全隔绝开来。 \n",
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
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;
	
	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	if( (int)me->query("kee") < 10 )
		return notify_fail("你的内力或气不够，没有办法练习覆雨剑法。\n");
	me->receive_damage("kee", 5);
	return 1;
}

int counter_attack_ratio()
{
	return 100;
}                 

int attack_ratio()
{	
	return 100;
}

int npc_only() {

	return 1;
}
