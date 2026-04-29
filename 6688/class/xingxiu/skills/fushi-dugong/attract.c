// attract.c
 
#include <ansi.h>
 
inherit SSERVER;


int perform(object me, object target)
{
        object soldier,ob;
        int poison;

        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能吸引毒虫为你作战！\n");

   //     if( (int)me->query_skill("leadership",1) < 100 )
   //             return notify_fail("你的统御之术不够，无法吸引毒虫为你作战！\n");

        if( (int)me->query_skill("fushi-dugong",1) < 120 )
                return notify_fail("你的腐尸毒功不够，无法吸引毒虫为你作战！\n");

        if( (int)me->query("faith") < 5000 )
                return notify_fail("你的师门忠诚度不够，那些毒虫干嘛要听你的？！\n");

        if (!objectp(ob = present("shengmu wangding",me) ) )
                return notify_fail("你身上没有神木王鼎，如何吸引毒虫？\n");  

        if( (int)me->query("force") < 2000 )
                return notify_fail("你的内力不够！\n");

        if( (int)me->query("gin") < 60 )
                return notify_fail("你的精神无法集中！\n");

        if( me->query_temp("myguard") >= 3 )
                return notify_fail("你最多只能吸引三只毒虫！\n");

        message_vision(HIB"$N将一些香料粉末放在神木王鼎里，顺势点燃香料隐藏在一边，静静地等待着毒虫的到来。\n"NOR, me);

        me->add("force", -500);
        me->receive_damage("sen", 60);
        
        poison=random(me->query_skill("fushi-dugong",1));

        seteuid(getuid());
        if( poison > 250 )
        {
                soldier = new("/class/xingxiu/skills/fushi-dugong/iceworm"); 
        }
        else if(poison > 100 && poison < 251)
        {
                soldier = new("/class/xingxiu/skills/fushi-dugong/snake"); 
        }
        else
        {
                soldier = new("/class/xingxiu/skills/fushi-dugong/wugong"); 
        }

        soldier->move(environment(me));
        soldier->invocation(me);
        return 1;
}


