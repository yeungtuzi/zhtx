#include <ansi.h>

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("xiezi_poison") < 4 ) {
                ob->apply_condition("xiezi_poison", 8);
                tell_object(ob, YEL"你觉得被咬的地方一阵麻痒！\n"NOR );
        }
}
varargs void revive(int quiet)
{
	remove_call_out("revive");
	return;
}
