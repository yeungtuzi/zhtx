/**************************************************************************/
// 纵横天下-I 
// ZHSCHOOL Contributed Source: From ES2 
// $Id: counterattack.c,v 1.2 2000/12/14 15:21:43 cmy Exp $
/**************************************************************************/
// shexin.c  摄心术

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        string weapon;
        if( !target ) target = offensive_target(me);

        if( (int)me->query_skill("duanjue-shengong",1) < 231) return notify_fail("你的断绝神功还不够高深，不能用摄心术");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("摄心术只能对战斗中的对手使用。\n");

        if ((int)me->query("force")<2000 || (int)me->query("kee")<1000) return notify_fail("你自己的状态不大好，强行迷惑对方会受到反噬的!\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        msg = HIW "$N使出断绝神功的「望穿秋水」，双眼凝视着$n，试图迷惑对方，";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 
          || random(me->query("spi")) > (int)target->query("spi")/2 ) {
                msg += "结果$p被$P的眼神所惑，停止了攻击！\n" NOR;
              target->start_busy( (int)me->query_skill("duanjue-shengong",1) / 20 + 2);
        } else {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(3);
        }
        me->add("force", -50);
        message_vision(msg, me, target);

        return 1;
}

