// fushi-dugong.c

inherit SKILL;

int valid_learn(object me)
{
	// 2026-04-30: unused variable commented out
	// object ob;
	int lv;

	lv = me->query_skill("fushi-dugong", 1);	
	if( (int)me->query("shen") > (-200 - 200 * lv) )
		return notify_fail("你太善良了，没有办法练腐尸毒功, 去多杀些正派人物吧。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="dugong";
}


int practice_skill(object me)
{
        if ( me->query("kee") < 50)
                return notify_fail("你的气不够，没有办法练习腐尸毒功．\n");
        if ( me->query("force") < 10)
                return notify_fail("你的内力不够，没有办法练习腐尸毒功．\n");
	me->receive_damage("kee", 30);
        me->add("force",-5);
	write("你按著所学练了一遍腐尸毒功。\n");
	return 1;
}

mapping enable_req()
{
	return ([
//                "force" : "huagong-dafa",
	]);
}

mapping level_req(int level)
{
	return ([
		"huagong-dafa" : 10,
	]);
}

int query_faith_req(int skill)
{
	return 10;
}
string perform_action_file(string action)
{
        return __DIR__"fushi-dugong/" + action;
}
