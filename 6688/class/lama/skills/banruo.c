inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("betrayer")  )
                return notify_fail("你没法学习这门功夫\n");
	if( me->query_skill("banruo",1) +20 > me->query_skill("zang-buddhi",1) )
		return notify_fail("你的佛法修为不够。\n");
//        if( me->query("gender") != "男性" )
//                return notify_fail("只有男性才能练这门刚猛的功夫。\n");
	if( me->query("str") < 25 )
		return notify_fail("你的力量不足，没法修习这门功夫。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("龙象般若功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("lama") + "/banruo/" + func;

}

string query_force_type() {

        return "佛家内功";
}

int query_faith_req(int skill) {
        return 8*skill;
}

void skill_improved(object me)
{
        int cor,level;

        cor = me->query("str"); 
        level = me->query_skill("banruo",1);

        if( level%30 == 9 && level > 30 && cor < level/2 )
        {
                tell_object(me,"你的龙象般若功更深了一层，你只觉得浑身上下脱胎换骨，无论举手投足，都贯注满了无数真力，原来这就是龙象之含义。\n");
                me->add("str",10);
        }
}
