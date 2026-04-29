// essencemagic.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("zang-buddhi") < 40
        ||      (int)me->query_skill("zang-buddhi")-20 <= (int)me->query_skill("space") )
		return notify_fail("你的佛法修为还不够高深，无法学习天外神识。\n");
	return 1;
}

string conjure_magic_file(string spell)
{
	return CLASS_D("lama") + "/space/" + spell;
}

mapping enable_req() {
        return( ([
                "force":"bolomiduo",
        ]) );
}

mapping level_req(int level) {

        return( ([
                "bolomiduo":10,
                "zang-buddhi":50,
        ]) );
}

int query_faith_req(int skill) {
	if(skill<20)
        	return 10;
	else 
		return skill*5+10;
}
