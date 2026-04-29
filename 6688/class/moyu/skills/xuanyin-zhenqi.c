// xuanyin-zhenqi.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("bellicosity") < (int)me->query_skill("xuanyin-zhenqi") * 50 )
                return notify_fail("你的杀气不够，无法领悟更高深的玄阴真气\。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("玄阴真气只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("moyu") + "/xuanyin-zhenqi/" + func;
}

string query_force_type() {

        return "邪派内功";
}

int query_faith_req(int skill) {
        return 3;
}

