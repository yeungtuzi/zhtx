// force-shield.c
// by masterall

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill,amount;

        if( target && target != me ) return notify_fail("真元护体只能对自己使用。\n");

        if( (int)me->query_temp("force-shield") ) return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force",1);

        if( me->query_skill("taiji-shengong") )     
                return notify_fail("你已经有太极神功作为防御了，何必多此一举呢？\n");

        if( me->query_skill("hunyuan-yiqi") )     
                return notify_fail("你已经有金钟罩作为防御了，何必多此一举呢？\n");

        if( me->query_skill("jiuyang-shengong") )     
                return notify_fail("你已经有九阳神功作为防御了，何必多此一举呢？\n");

        if( me->query_skill("necromancy") )     
                return notify_fail("你的茅山道术难道不能护体吗，非要再给自己加个防护累不累啊？\n");

        if ( skill < 300 )
                return notify_fail("你的内功心法修为还不够，难以产生护体之效。\n");

        if( (int)me->query("force") < (int)me->query("max_force") + 1000 )     
                return notify_fail("你体内的真气不够。\n");

        if( (int)me->query("max_force") < 4000 )     
                return notify_fail("你的内力太低了，无法使用真元护体。\n");

        message_vision(HIY"$N屏息凝神，潜运内功，顿时体内的真气四处游走盘旋，回护着周身要穴...\n"NOR,me);

        amount = skill/8+me->query("max_force")/15; 
        me->add("force", -amount);
        me->add_temp("apply/armor", amount); 
        me->add_temp("apply/armor_vs_force", amount); 
        me->set_temp("force-shield", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, amount :), skill);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->add_temp("apply/armor_vs_force", - amount);
        me->delete_temp("force-shield");
        tell_object(me, HIR"你的真气重新归于丹田，『真元护体』的效果消失了。\n"NOR);
}

