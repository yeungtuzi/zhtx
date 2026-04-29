// essencemagic.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("zang-buddhi") < 50
        ||      (int)me->query_skill("zang-buddhi")-20 <= (int)me->query_skill("essencemagic") )
		return notify_fail("你的佛法修为还不够高深，无法学习八识神通。\n");
	return 1;
}

string conjure_magic_file(string spell)
{
	return CLASS_D("lama") + "/essencemagic/" + spell;
}

/*
mapping enable_req() {
        return( ([
              "force":"gouyee",
               "force":"banruo",
                "force":"bolomiduo",
        ]) );
}
*/

mapping level_req(int level) {

        return( ([
                "bolomiduo":10,
                "zang-buddhi":50,
//                "spells":250,
        ]) );
}

int query_faith_req(int skill) {
	if(skill<20)
        	return 10;
	else 
		return skill*5+10;
}
