// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("kee", 15);
        me->receive_damage("sen", 15);
        me->apply_condition("xiezi_poison", duration - 1);
        me->save();
        tell_object(me, HIG "你中的蝎毒发作了！\n" NOR );
        if( duration < 1 ) return 0;
        return 1;
}
