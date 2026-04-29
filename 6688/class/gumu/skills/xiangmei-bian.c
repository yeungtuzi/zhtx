// by Yeung

inherit SKILL;
mapping *action = ({
([	"action" : "「对鐏前，忆前欢」，$N向前轻上一步，左手轻轻举起自口边划过，手中$w轻轻颤动，化为无数鞭影将$n围在中间",

	"force" : 80,
	"dodge" : 20,
	"damage" : 40,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "「曾把梨花，寂寞泪阑干」,$N面上凄然，手中$w一收，鞭影散去，摇摆不定地刺向$n",

	"force" : 100,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「春工已觉，点破香梅萼」，手中$w急收急挥，闪电般地点向$n的头部",
	"force" : 120,
	"dodge" : 10,
	"damage" : 80,
        "lvl" : 29,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使出一式「和别泪，看青山」，面上露出企盼之色，手中的$w又掉转回来拦腰兜向$n",

	"force" : 100,
	"dodge" : 10,
	"damage" : 80,
        "lvl" : 39,
	"damage_type" : "瘀伤"
]),	
([	"action" : "$N轻轻吟道：「多谢月相怜，今宵不忍圆」，手中$w一抖，化为两道弧光，随着$N身体的飞舞划向$n",

	"force" : 100,
	"dodge" : 10,
	"damage" : 100,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),
([	"action" : "「水云间，俏无言」，$N略移纤腰，手中$w回射，只见一道光箭电射$n$l",

	"force" : 100,
	"dodge" : 5,
	"damage" : 120,
	"attack" : 20,	
        "lvl" : 49,
	"damage_type" : "刺伤"
]),
([	"action" : "$N轻叹：「争奈醒来，愁恨又依然」，手中$w若有所思，悄然点向$n",
	"force" : 150,
	"dodge" : 5,
	"damage" : 100,
	"attack" : 20,	
        "lvl" : 79,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N脸显惆怅之意，一式「少饮清欢，银烛花频落」，手中$w升起，在空中划出无数圆圈，绵绵不绝地落向$n",
	"force" : 180,
	"dodge" : -5,
	"damage" : 120,     
	"attack" : 30,
        "lvl" : 119,
	"damage_type" : "瘀伤"
])
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yunu-xinfa", 1) < 20)
		return notify_fail("你的玉女心法火侯太浅。\n");
	if ((int)me->query_skill("meinu-quan", 1) < 20)
		return notify_fail("你的美女拳法火候太浅。\n");
	return 1;
}

//按次序出招
mapping query_action(object me, object weapon)
{
//        int i, level;
        me->add_temp("skills/xiangmei-bian",1);
        if( me->query_temp("skills/xiangmei-bian") >= sizeof(action) ) me->set_temp("skills/xiangmei-bian",0);
  	return action[me->query_temp("skills/xiangmei-bian")];      
	        
//        level   = (int) me->query_skill("xiangmei-bian",1);        
//        for(i = sizeof(action); i > 0; i--)
//                if(level > action[i-1]["lvl"])
//                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 35)
		return notify_fail("你的体力不够练香梅鞭法。\n");
	me->receive_damage("kee", 30);
	return 1;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});
string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int query_faith_req(int skill) {
	return 10+skill*3;
}


