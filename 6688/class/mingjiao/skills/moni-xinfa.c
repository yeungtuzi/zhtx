inherit FORCE;

int valid_enable(string usage)
{
return usage == "force";
}

int valid_learn(object me)
{
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会摩尼心法。\n");

	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"moni-xinfa/" + func;
}

string query_force_type() {

	return "佛家内功";
}

int query_faith_req(int skill) {
	return skill*3+3;
}

