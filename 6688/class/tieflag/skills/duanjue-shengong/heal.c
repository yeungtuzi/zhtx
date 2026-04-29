/**************************************************************************/
// 纵横天下-I 
// ZHSCHOOL Contributed Source: From ES2 
// $Id: heal.c,v 1.2 2000/12/14 15:21:43 cmy Exp $
/**************************************************************************/
// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功\疗伤？找死吗？\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 4 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIR "你全身放松，坐下来开始运功\疗伤。\n" NOR);
        message("vision",
                HIR + me->name() + "坐下来运功\疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);

        me->receive_curing("kee", 20 + (int)me->query_skill("force")/4 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}

