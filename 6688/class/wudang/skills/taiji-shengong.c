// taiji-shengong.c 太极神功
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int lvl = (int)me->query_skill("taiji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < lvl / 11; j++) t *= 2;

	t= t*2;
	t *= (10+me->query("betrayer"))/10;
	if( t < 0 || t > 2000000000 )
		t = 2000000000;

	if ( me->query("gender") == "中性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，"
			+RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

        if (lvl > 10 && (int)me->query("shen") < t * 100 && lvl < 251) 
		return notify_fail("你的侠义正气太低了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

int query_relieve_coff() {
        return 80;
}

string query_relieve_message() {
	return CYN "$n默运内功,使出太极神功的「卸」字决，将$N的一击之力卸去大半。\n"NOR;
}

string query_force_type() {
	return "道家内功";
}

int query_faith_req(int skill) {
	return 10+skill*9;

}
