//当年李秋水数度遇险,都靠小无相功得以保全,也许小无相功的疗伤功能比较强吧!


#include <ansi.h>

int exert(object me, object target)
{
        if( (int)me->query("eff_kee") == (int)me->query("max_kee") )
                return notify_fail("你并没有受伤啊!\n");

        if( (int)me->query("force") < 100 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 10 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        me->start_busy(1);
        if( !me->is_fighting() ) {
                me->add("force", -50);
                write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
                message("vision", HIW + me->name() + "坐下来运功疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n" NOR, environment(me),
me);

                me->receive_curing("kee", 30 + random((int)me->query_skill("force")/2) );
        }
        else {
                me->add("force", -100);
                write( HIW"你暗将内力运转了一个大周天, 感觉好多了。\n"NOR);

                me->receive_curing("kee", 10 + random((int)me->query_skill("force")/4) );
        }

        return 1;
}
