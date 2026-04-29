// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	
		"action":		"$N左手剑诀，右手前趋，使出一招「失空斩」，手中$w回抽，斩向$n$l",
		"force":		40,		
		"damage":		40,
		"lvl" : 		0,
		"damage_type":	"割伤"
	]),
	([	
		"action":		"$N纵身一跃而起，一式「宇宙锋」，连人带$w直扑入$n怀中，$w顺势刺出",
		"attack":		10,
		"force":		60,		
		"damage":		60,
		"lvl" : 		20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N长笑一声，使出一招「天道秘」，手中$w逼出尺许青芒，以气驭剑，$w\n"+
					"化作一道电光射向$n",
		"attack":		15,
		"force":		120,		
		"damage":		100,
		"lvl" : 		40,		
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N身形伫立不动，手中$w遥指远方大地，突然间，$w一阵奇异地颤动，\n"+
					"一式「前生悟」，剑气直发，逼向$n",
		"attack":		20,
		"parry" : 		15,
		"lvl" : 		80,		
		"force":		130,
		"damage":		110,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N使出一招「碎梦惊」，身形展动，绕着$n身前身后不停旋转，手中$w幻出\n"+
					"朵朵剑花，正当$n眼花缭乱之际，蓦然，万千光芒敛去，$w突围直出，\n"+
					"挟万钧雷霆之势刺向$n$l",
		"dodge":		20,
		"attack":		25,
		"lvl" : 		100,		
		"force":		150,
		"damage":		120,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping enable_req() {

        return( ([ 
                "force":"moni-xinfa",       
        ]) );

}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("moni-sword",1);

        for(i = sizeof(action); i > 0; i--)
                        if(level > action[i-1]["lvl"])
                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object ob;
	int kee_cost;
	
	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	if( (int)me->query("kee") < 40
	||	(int)me->query("force") < 100 )
		return notify_fail("你的内力或气不够，没有办法练习摩尼剑法。\n");
	
	kee_cost = ((int)me->query_skill("moni-sword",1)/60+1)*10;
	me->receive_damage("kee", kee_cost);
	write("你按著所学练了一遍摩尼剑法。\n");
	return 1;
}
