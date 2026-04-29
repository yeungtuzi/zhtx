// heart_sense.c

#include <ansi.h>

int conjure(object me, object target)
{
        int atman_gain;

        if( target && target!=me )
                return notify_fail("「神识」只能用来恢复自己的灵力。\n");

        if( (int)me->query("force") < 30 )
                return notify_fail("你的内力不够。\n");

        
        atman_gain =  10 + (int)me->query_skill("magic")/5;
        if( atman_gain + (int)me->query("atman") > (int)me->query("max_atman") )
                me->set("atman", (int)me->query("max_mana"));
        else
                me->add("atman", atman_gain);
        me->add("force", -30);
        me->receive_damage("sen", 10);

        message_vision(
                HIY "$N闭目凝神，印堂发出一道金芒罩住$N的全身...\n" NOR, me);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

