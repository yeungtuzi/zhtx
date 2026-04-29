// snake_poison.c

#include <ansi.h>
#include <skill.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

        me->receive_wound("sen", duration*2);
        me->receive_wound("kee", duration*15);
        me->receive_wound("gin", duration*3);

        if( me->query_skill("dugong",1) >= 120 )
                me->apply_condition("snake_poison", duration - 2);
        else
                me->apply_condition("snake_poison", duration - 1);

        message_vision(HIG"$N的脸上渗出一滴碧水, 身子不由自主地抖了一下.\n"NOR,me);
        tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );

        return 1;
}

