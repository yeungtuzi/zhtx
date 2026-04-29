// summon.c
 
#include <ansi.h>
 
inherit SSERVER;


int exert(object me, object target)
{
        object soldier;
        int skill;


        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤天邪灵兽！\n");

   //     if( (int)me->query_skill("leadership",1) < 100 )
   //             return notify_fail("你的统御之术不够，无法召唤天邪灵兽！\n");

        if( (int)me->query_skill("celestial",1) < 200 )
                return notify_fail("你的天邪神功不够，无法召唤天邪灵兽！\n");

        if( (int)me->query("faith") < 5000 )
                return notify_fail("你的师门忠诚度不够，天邪灵兽干嘛要听你的？！\n");

        if( (int)me->query("force") < 2000 )
                return notify_fail("你的内力不够！\n");

        if( (int)me->query("gin") < 60 )
                return notify_fail("你的精神无法集中！\n");

        if( me->query_temp("myguard") >= 3 )
                return notify_fail("你最多只能召唤三只天邪灵兽！\n");

        message_vision(HIR"$N鼓足中气长啸一声，"+HIY"天地日月顿生共鸣，"+HIW"遥远的虚空似乎传来了一声骇人心魄的低嚎……\n"NOR, me);
        me->add("force", -500);
        me->receive_damage("sen", 60);
        me->start_busy(1);

        skill = random(me->query_skill("celestial", 1));
        seteuid(getuid());

        if( skill <= 100 )
                soldier = new("/class/fighter/celestial/dog"); 

        else if ( skill > 100 && skill < 150)
                soldier = new("/class/fighter/celestial/tiger"); 

        else
                soldier = new("/class/fighter/celestial/kylin"); 

        soldier->move(environment(target));
        soldier->invocation(me);

        return 1;
}

