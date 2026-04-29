// chillgaze.c
 
#include <ansi.h>
 
inherit SSERVER;


int exert(object me, object target)
{
        object soldier;
  //      object me,target;
  //      me=this_player();

        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤护法神鸟！\n");

   //     if( (int)me->query_skill("leadership",1) < 100 )
   //             return notify_fail("你的统御之术不够，无法召唤护法神鸟！\n");

        if( (int)me->query_skill("iceforce",1) < 200 )
                return notify_fail("你的意寒神功不够，无法召唤护法神鸟！\n");

        if( (int)me->query("faith") < 5000 )
                return notify_fail("你的师门忠诚度不够，护法神鸟干嘛要听你的？！\n");

        if( (int)me->query("force") < 2000 )
                return notify_fail("你的内力不够！\n");

        if( (int)me->query("gin") < 60 )
                return notify_fail("你的精神无法集中！\n");

        if( me->query_temp("myguard") >= 3 )
                return notify_fail("你最多只能召唤三只护法神鸟！\n");

        message_vision(HIM"$N凄婉的悲鸣一声，如歌如泣，天地为之动容，日月因其变色，突然间…………\n"NOR, me);
        me->add("force", -500);
        me->receive_damage("sen", 60);
        me->start_busy(1);


        seteuid(getuid());
        if( random(5)<2 )
                soldier = new("/class/dancer/iceforce/phoenix"); 
        else
                soldier = new("/class/dancer/iceforce/leipeng"); 

        soldier->move(environment(target));
    //    soldier->set_level(me->query_skill("cloudstaff",1));
        soldier->invocation(me);
     //   me->add_temp("myguard",1);
        return 1;
}
