#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	object *obs;
	int i;
	
	if( me->query_skill("huagong-dafa", 1) < 30 )
		return notify_fail("你的化功大法运用不够熟练，强行修练会走火入魔的。\n");	
        if( (int) me->query_skill("huagong-dafa", 1) >= 380)
                return notify_fail("你的化功大法已经不能再练了。\n");

	if( me->query("kee") < 35 || me->query("force") < 15 )
		return notify_fail("你现在的状态没有办法修练化功大法。\n");

	obs = all_inventory(me);
	
	for(i=0; i< sizeof(obs); i++)
		if( !obs[i]->query("poison_available") )	continue;
		else break;

	if( i == sizeof(obs) )
        	return notify_fail("化功大法必须找毒物来练。\n");

	obs[i]->add("poison_available", -1);
	
	tell_object(me, "你盘膝坐下，将" + obs[i]->name() + "置入掌心，依着所学潜运化功大法，将" + obs[i]->name() + "之毒吸入体内。\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);
	/*if( me->query_condition("huagong") ){
		me->clear_condition("huagong");
		me->apply_condition("huagong", 420);
	}*/
	if( !obs[i]->query("poison_available") )	obs[i]->die();
	return 1;
}

string exert_function_file(string func)
{
        return __DIR__"huagong-dafa/" + func;
}

int query_property()
{
	return 20;
}

int query_faith_req(int skill)
{
	return 10 + skill * 13;
}

string query_force_type()
{
	return "化功大法";
}

void skill_improved(object me)
{
	if( me->query_skill("huagong-dafa", 1) == 30 ){
		tell_object(me, HIY"化功大法已经与你的全身息息相关，以后每七天之内必须炼毒入体(practice)一次，否则体内蓄积之毒反噬过来，将全身溃烂而死！\n"NOR);
		tell_object(me, HIY"切记！切记！！\n"NOR);
	/*	if( !me->query_condition("huagong") )
			me->apply_condition("huagong", 420);*/
		return;
	}

	if( me->query_skill("huagong-dafa", 1) > 120 )
		tell_object(me, "化功大法只能消敌内力，却不能引为我用，为何？你心里想。\n");
	if( me->query_skill("huagong-dafa", 1) > 30 )
/*	if( !me->query_condition("huagong") )
		me->apply_condition("huagong", 420);*/
	return;
}
