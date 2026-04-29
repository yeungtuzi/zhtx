// dugu-jiujian.c 独孤九剑

inherit SKILL;

mapping *action = ({
([      
        "action" : "$N斜斜得向$n的$1刺出一剑，所刺之出令人出乎意料。",
        "force" : 10,
        "parry" : 10,
		  "attack": 10,
        "damage" : 20,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N向前跨上一步，右手$w平淡无奇的伸向$n的$l，根本无招可言。",
        "force" : 20,
        "parry" : 10,
        "attack": 10,
        "damage" : 50,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N手中$w突然撞向自己的$l，就在此时，一转向$n的$l挥去。",
        "force" : 40,
        "parry" : 15,
		  "attack": 15,
        "damage" : 70,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N将手中$w舞成一片，直砍$n的$l",
        "force" : 50,
        "parry" : 20,
	     "attack": 15,
        "damage" : 90,
        "lvl" : 30,
        "damage_type" : "砍伤"
]),
([      
        "action" : "$N突然将$w抛向空中，剑锋直向$n的$l刺去。$N跟上一步，又接住了$w。",
        "force" : 60,
        "parry" : 20,
  	     "attack": 20,
        "damage" : 100,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N身形急转，$w从一个不可思意的角度刺向$n的$l",
        "force" : 60,
        "parry" : 30,
	     "attack": 20,
        "damage" : 120,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N身子一晃，抢步上前，出人意料的将$w交给左手，右食指点向$n的$l",
        "force" : 70,
        "parry" : 30,
	     "attack": 25,
        "damage" : 140,
        "lvl" : 100,
        "damage_type" : "瘀伤"
]),
([      
        "action" : "$N右腿半屈般蹲，剑尖虚指，转身撩向$n的$l",
        "force" : 80,
        "parry" : 30,
	     "attack": 25,
        "damage" :150 ,
        "lvl" : 120,
        "damage_type" : "刺伤"
]),
([ 
        "action" : "$N回身拧腰，右手虚抱，$w中宫直进，刺向$n的$l",
        "force" : 90,
        "dodge" : 30,
	     "attack": 30,
        "damage" : 220,
        "lvl" : 160,
        "damage_type" : "刺伤"
]),
});



int valid_enable(string usage) { return (usage == "sword") ; }

int valid_learn(object me)
{
        if(me->query_skill("huashan-jianfa",1)<150 && me->query_skill("sword",1)<150)
		          return notify_fail("你的剑术修为太低，无法领会独孤九剑的奥秘");
		  if(me->query_skill("zong-jue",1)+19<me->query_skill("dugu-jiujian",1))
                return notify_fail("你的「总诀式」修为太低，无法进一步领会独孤九剑的奥秘。\n");
        if(me->query("family/master_id")!="feng qingyang")
                return notify_fail("独孤九剑只能向风清扬学。\n");
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("dugu-jiujian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;
        return notify_fail("独孤九剑只能通过学来提高熟练度。\n");
         
}

string perform_action_file(string action)
{
        return __DIR__"dugu-jiujian/" + action;
}

int counter_attack_ratio() {

	return 100;
}

int attack_ratio() {
	return 50;
}

int query_sheng_ke(string skill) 
{
//	if(skill == "pixie-sword" ) return 300;
   if(skill == "taiji-jian") return 100;
	return 300;
}

mapping enable_req() 
{

	return( ([ 
		"dodge":"yan-shuangfei",	
	]) );

}

mapping level_req(int level) 
{

	return( ([
		"sword":150,	
		"yan-shuangfei":150,
		"huashan-jianfa":150,
	]) );
}

int query_faith_req(int skill) 
{
	return 10*skill+1;
}
