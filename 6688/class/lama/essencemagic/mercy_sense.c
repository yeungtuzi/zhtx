// void_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
        int lvl;

        if( target ) return notify_fail("寂识神通只能对自己使用。\n");

        if( me->query("atman") < 50 )
                return notify_fail("你的灵力不够！\n");

        lvl = (int) me->query_skill("essencemagic",1);

        if( me->query("gin") <= 50 )
                return notify_fail("你的精不够！\n");

        if( lvl <= 100 )
                return notify_fail("你的八识神通等级不够，无法自行修炼！\n");

        if( lvl > me->query_skill("magic", 1)-21)
                return notify_fail("你的神通修为已经很高了，再修炼下去只怕不会有结果。\n");

        me->add("atman", -50);
        me->receive_damage("gin", 50);
        message_vision(HIY "$N盘膝而座，开始运用寂识神通静思入定 ...\n" NOR, me);

        if( random(me->query("msc")) < 10  ) 
        {
        write( HIR "你觉得脑中一片混乱，修炼了半天一无所获！\n" NOR );
        return 1;
        }else{
        me->improve_skill("essencemagic", me->query_spi()+me->query_msc());
        write( HIG "你的八识神通提高了！\n" NOR );
        return 1;
        }

}
