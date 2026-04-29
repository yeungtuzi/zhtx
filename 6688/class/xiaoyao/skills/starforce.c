// starforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("星河心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"starforce/" + func;
}

int query_property()
{
	return 12;
}

string query_force_type() {return "道家内功";}

int query_faith_req(int skill) {return 100;}
