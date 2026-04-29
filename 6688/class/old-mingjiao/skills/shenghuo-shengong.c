// shenghuolin.c
// Writed by yuer

inherit SKILL;

mapping *action = ({
([      "action":"$N身形一晃，“啪”的一声，抓住$n的后领，远远掷了出去.",
        "force" : 20,
        "dodge" : -10,
	"attack": 15,
        "damage": 25,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "淤伤"
]),
([      "action":"$N$w向$n咽喉点去，$w忽然尾端一弹，急点$n手腕",
        "force" : 40,
	"attack": 15,
        "dodge" : -10,
        "damage": 30,
        "lvl" : 10,
	"weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然连翻三个筋斗，白影一闪,有如一条白链，$w向$n重重击去。",
        "force" : 60,
        "dodge" : 5,
	"attack": 15,
        "damage": 45,
        "lvl" : 25,
	"weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":"突然间$N向后摔出，$w从一个不可思议的角度电般急射向$n。",
        "force" : 100,
       "dodge" : 5,
	"attack": 15,
        "damage": 50,
        "lvl" : 40,
	"weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$N身体急转，旋风般飞起两脚，$w乘虚刺向$n的小腹，端的是神妙无伦，不可思议",
        "force" : 160,
       "dodge" : 5,
	"attack": 15,
        "damage": 70,
        "lvl" : 55,
	"weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$n攻向$N的$l，$N不退反进，忽然低头向$n撞来，攻了$n一个措手不及",
        "force" : 170,
       "dodge" : 5,
	"attack": 15,
        "damage": 80,
        "lvl" : 70,
	"weapon" : "左手",
        "damage_type":  "刺伤"
]),
([      "action":"$N跃身半空，忽然向$n头顶坐了下来，甚是怪异，竟以臀部攻人。",
        "force" : 270,
        "dodge" : 5,
	"attack": 25,
        "damage": 100,
        "lvl" : 80,
	"weapon" : "",
        "damage_type":  "淤伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry"; 
}
int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("你的九阳神功火候太浅。\n");
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
        level   = (int) me->query_skill("shenghuo-shengong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
/*
int valid_practice(object me)
{
        return notify_fail("圣火神功不能练的方式。\n");
}
*/


int practice_skill(object me)
{
        if( (int)me->query("kee") < 35
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习圣火神功。\n")
;
        me->receive_damage("kee", 35);
        me->add("force", -3);
        write("你按著所学练了一遍圣火神功。\n");
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"shenghuo-shengong/" + action;
}
string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


mapping enable_req() {

	return( ([ 
		"force":"jiuyang-shengong",	
		"dodge":"taxue-wuhen",	
	]) );

}

mapping level_req(int level) {

	return( ([
		"jiuyang-shengong":20,	
		"taxue-wuhen":20,	
	]) );
}

int query_faith_req(int skill) {
	return skill*3+3;
}
