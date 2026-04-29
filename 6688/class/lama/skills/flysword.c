// /daemon/skill/flysword.c
// 天翔剑法
// by mscat
//
// 这是给新纵横天下里卜鹰设计的剑法
// 每句是一招
// 也可以算是对mud的一种感受吧:pppp
// 
// 莫道江湖路漫长
// 冷月如霜
// 孤星三两
// 方断离人肠
// 侠骨柔情莫忘
// 任峰涛云怒
// 剑魄刀光
// 振翅九天翔
//
// 应知前路当有险
// 千里黄沙
// 万里鹰扬
// 谈笑逐四方
// 看年华流水
// 逝者苍茫
// 独立我山岗

inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「冷月如霜」，手中$w带起一条弧线扫向$n的$l",
	"parry" : 20,
	"force" : 120,
        "dodge" : -20,
	"damage": 30,
	"damage_type":	"割伤"
]),
([	"action":"$N使一招「孤星三两」,手中的$w向$n的$l连连疾点",
	"force" : 80,
        "dodge" : 10,
	"damage": 50,
	"parry"	: 30,
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w自左下至右上划出,正是一招「方断离人肠」",
	"force" : 160,
        "dodge" : 5,
	"damage": 55,
	"parry"	: 40,
	"damage_type":	"割伤"
]),
([	"action":"$N长啸一声，一式「任峰涛云怒」，剑势如潮水般涌向$n",
	"force" : 180,
       	"dodge" : -20,
	"damage": 200,
	"parry"	: -20,
	"damage_type":	"砍伤"
]),
([	"action":"$N一式「剑魄刀光」，手中$w忽变刀招,大开大合,砍向$n的$l",
	"force" : 220,
        "dodge" : -25,
	"damage": 200,
	"parry" : 30,
	"damage_type":	"砍伤"
]),
([	"action":"$N凌空跃起，手中$w自内向外挥出，一式「振翅九天翔」，斜挑$n的$l",
	"force" : 260,
        "dodge" : 35,
	"damage": 220,
	"parry"	: 30,
	"damage_type":	"割伤"
]),
([	"action":"$N一式「千里黄沙」，手腕急抖，$w化作万点金光，刺向$n的$l",
	"force" : 320,
        "dodge" : 15,
	"damage": 125,
	"parry"	: 30,
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「万里鹰扬」，$w飘忽不定，$n的全身皆在剑光笼罩之下",
	"force" : 300,
        "dodge" : -20,
	"damage": 100,
	"parry"	: 20,
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w光芒一盛,一式「看年华流水」，掠过$n的$l",
	"force" : 280,
        "dodge" : -5,
	"damage": 90,
	"parry"	: 10,
	"damage_type":	"割伤"
]),
([
	"action":"$N仰首向天,似乎对$n不理不睬,一式「逝者苍茫」，无声无息地点向$n的$l",
	"force" : 300,
	"dodge" : -20,
	"damage": 250,
	"parry" : -30,
	"damage_type":  "刺伤"
]),
([
        "action":"$N抱元守一,手中$w当胸一竖,一式「独立我山岗」，无形剑气如潮水般涌向$n",
	"force" : 400,
	"dodge" : -50,
	"damage": 330,
	"parry" : 30,
	"damage_type":  "内伤"
])
});

int valid_enable(string usage) 
{ 
	return usage == "sword" || usage == "parry"; 
}

int valid_learn(object me) 
{ 
	object ob;
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1; 
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	if ((int)me->query("kee") < 2500)
		return notify_fail("你的体力不够练天翔剑法。\n");
	me->receive_damage("kee", 2500);
	return 1;
}

int effective_level() { return 10;}

string *parry_msg = ({
        "$n使一招「莫道江湖路漫长」，大步踏向一旁，避开了$N攻来的$w。\n",
        "$n使出一招「方断离人肠」，手中的$v自左下至右上一划，将$N的攻势完全封死。\n",
        "$n手中$v微微扬起，一招「侠骨柔情莫忘」，似攻非攻，似守非守，\n"+
		"$N发现自己的$w竟然完全无法抢到空隙进去。\n",
	"但是$n凌空跃起,一招「振翅九天翔」，避开了$N攻来的$w。\n",
	"$n使出一招「应知前路当有险」，抢先从$N攻来的$w一旁闯过。\n",
	"$n抱元守一,手中$w当胸一竖,一式「独立我山岗」，无形剑气如潮水般荡开$N的$w。\n"
});

string *unarmed_parry_msg = ({
	"$n使一招「莫道江湖路漫长」，大步踏向一旁，避开了$N的攻势。\n",
	"$n使出一招「方断离人肠」，手中的$v自左下至右上一划，将$N的攻势完全封死。\n",
	"但是$n凌空跃起,一招「振翅九天翔」，避开了$N的攻势。\n",
	"$n使出一招「应知前路当有险」，抢先从$N身侧闯过。\n",
	"$n使出一招「谈笑逐四方」，边绕着$N疾走，边将其攻势一一接下。\n",
	"$n抱元守一,手中$w当胸一竖,一式「独立我山岗」，无形剑气如潮水般荡开$N的攻势。\n"
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 1;
}

int practice_bonus()
{
        return 11;
}

int black_white_ness()
{
        return 2;
}
int query_faith_req(int skill) {
        return 100*skill+10000;
}
