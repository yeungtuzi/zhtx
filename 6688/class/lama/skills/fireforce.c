// /daemon/skill/fireforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("烈火神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("engineer")+"/fireforce/"+func;
}
int effective_level() { return 20; }

int learn_bonus()
{
        return 7;

}
int practice_bonus()
{
        return 5;
}
int black_white_ness()
{
        return 25;
}

int query_faith_req(int skill) {
        return 100*skill+10000;
}

