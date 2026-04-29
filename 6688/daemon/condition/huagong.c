// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( me->query_skill("huagong-dafa") < 30 )	return 0;

        if(duration<0){ 
		tell_object(me, HIR"由于久久未能炼毒入体，你全身积蓄的毒质反噬回来啦！\n"NOR);
		tell_object(me, HIR"你体内毒质便如泄了闸门的洪水一样，完全失去了控制，在你的五脏六腑内乱窜，渐入人身要害。。。"NOR);
		tell_room(environment(me), HIY+me->name()+"突然象发了疯似的又是叫，又是跳，又是爬，又是滚，情景骇人。。。"NOR, me);
		me->die();
		return 0;
	}
			
        me->apply_condition("rose_poison", duration - 1);
	if( duration % 60 == 0 && duration / 60 < 3 ){
        	tell_object(me, HIY "你觉得体内毒质开始骚动，随时都有可能失去控制，想是很久未炼毒入体的缘故！\n" NOR );
		me->receive_wound("sen", 50);
	}
        return 1;
}
