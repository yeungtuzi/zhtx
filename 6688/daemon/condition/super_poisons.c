// super_poisons.c

#include <ansi.h>
#include <skill.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;


        me->receive_wound("sen", duration*5);
        me->receive_wound("kee", duration*20);
        me->receive_wound("gin", duration*5);

        if( me->query_skill("dugong",1) >= 120 )
                me->apply_condition("super_poisons", duration - 2);
        else
                me->apply_condition("super_poisons", duration - 1);

        message_vision(HIY"$N的脸上渗出一滴黄水, 身子不由自主地抖了一下.\n"NOR,me);
        tell_object(me, HIR "你中的" HIY "不死不休毒" HIR "发作了！\n" NOR );

        return 1;
}

