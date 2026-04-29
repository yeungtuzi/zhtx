// bahuang.c
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int practice_skill(object me)
{
        return notify_fail("八荒六合唯我独尊功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"bahuang-gong/" + func;
}

int query_property()
{
	return 9;
} 

void skill_improved(object me)
{
	int i;

	i = me->query_skill("bahuang-gong", 1);

	if( i == 1 ){
		tell_object(me, HIY"八荒六合唯我独尊功每三十年返老还童一次，以后每练一日恢复一日功力，直至全部恢复。\n"NOR);
	//	me->set("skill_mark/learned_bahuang", me->query("age"));
		return;
	}
}

int query_faith_req(int skill)	{return	100 + skill * 5;}
string query_force_type()       {return "北冥神功";} 
