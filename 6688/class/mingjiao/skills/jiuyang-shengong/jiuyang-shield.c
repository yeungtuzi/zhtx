// jiuyang-shield.c
// by yeung

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill,amount;

        if( target && target != me ) return notify_fail("你只能用九阳神功来加强自身的防护效果。\n");

        if( (int)me->query_temp("jiuyang-shield") ) return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_temp("broke-shield") ) return notify_fail("你的体内的真气已经被打散了，无法继续提精运气。\n");

        skill = me->query_skill("force");
        amount = skill/10+me->query("max_force")/20; // 最大情况 300/10 + 2600/20 = 160 ,更强调内力作用

        if( me->query("gender") != "男性" )
                amount /= 2;

        if ( skill < 100 )
                return notify_fail("你的九阳神功修为还不够，难以产生护体之效。\n");
        if( (int)me->query("force") < amount + 50 )     
                return notify_fail("你的内力不够。\n");

        message_vision(HIR"$N专心凝神，默运九阳神功，一股纯阳真气开始在周身游走盘旋...\n"NOR,me);

        me->add("force", -amount);
        me->add_temp("apply/armor", amount*2); 
        me->add_temp("apply/armor_vs_force", amount); 
        me->set_temp("jiuyang-shield", 1);

        if ( me->query_skill("jiuyang-shengong", 1) >= 300 && random(me->query("con")) > 40)
//加入阴阳之盾，九阳等级足够高会随机出现，防止小点伤害,by masterall
{
        message_vision(HIG"$N突然在运功中悟到了天地万物阴阳互生水火相融的至理，不由得仰天长笑！\n"NOR,me);
        me->set_temp("yinyang-shield", 1);
}

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, amount :), skill);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", -amount*2); 
        me->add_temp("apply/armor_vs_force", - amount);
        me->delete_temp("jiuyang-shield");
        me->delete_temp("yinyang-shield");
        tell_object(me, "你的九阳真气运行完毕，内力重新归于丹田。\n");
}

