inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("燎原心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"liaoyuan-force/" + func;

}

string query_force_type() {
	return "道家内功";
}
int npc_only() {

	return 1;
}
