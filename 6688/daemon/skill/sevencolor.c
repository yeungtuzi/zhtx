//sevencolor.c

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("sevencolor", 1);
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t *= 2;

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");

        if (lvl > 10 && (int)me->query("shen") < t * 100)
                return notify_fail("你的侠义正气太低了。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("七彩玲珑心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return "/class/legend/sevencolor/" + func;
}

mapping level_req(int level) {

        return( ([
                "force":100,    
        ]) );
}

int query_faith_req(int skill) {
        return skill*3 +10 ;
}

string query_force_type() {

        return "道家内功";
}

