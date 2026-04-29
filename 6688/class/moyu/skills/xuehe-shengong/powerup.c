// 血河霸气

#include <ansi.h>

int exert(object me, object target, int amount)
{       
        int skill,force;  
        skill = me->query_skill("force");  
        if(skill < 55) return notify_fail("你的内功心法等级不够！\n"); 
        if( target && target != me)
                return notify_fail("你只能对自己使用血河霸气。\n");
        if( (int)me->query("force") < 400 )
                return notify_fail("你的真气不够。\n");
        message_vision(
                RED "$N运起血河霸气，全身骨节不绝地发出一阵阵噼啪轻响，一阵血雾缓缓笼罩全身！\n" NOR,me);
        force=me->query_skill("force")/2;
        me->set("force_factor",force/2+ (int)(skill*skill*skill/90000));
        me->add("force",-400);
        if( me->is_fighting() )
                me->start_busy(2);
        return 1;
}