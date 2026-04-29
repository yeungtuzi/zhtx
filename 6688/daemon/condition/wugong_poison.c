// wugong_poison.c

#include <ansi.h>
#include <skill.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

        me->receive_wound("sen", duration);
        me->receive_wound("kee", duration*10);
        me->receive_wound("gin", duration);

        if( me->query_skill("dugong",1) >= 120 )
                me->apply_condition("wugong_poison", duration - 2);
        else
                me->apply_condition("wugong_poison", duration - 1);

        message_vision(HIR"$N的脸上渗出一滴血水, 身子不由自主地抖了一下.\n"NOR,me);
        tell_object(me, HIR "你中的蜈蚣赤毒发作了！\n" NOR );

        return 1;
}

