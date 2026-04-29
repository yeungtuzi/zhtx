// 嫁衣神通
// by masterall


#include <ansi.h>

inherit F_CLEAN_UP;
inherit SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( wizardp(me) )return notify_fail("巫师限制使用此命令!\n");

        if( !target) target=me;

        if( me->is_fighting() )
                return notify_fail("战斗中不能使用嫁衣神通！\n");

        if( !target || !target->is_character() || target->is_corpse())
                return notify_fail("你只能对活物使用嫁衣神通！\n");

        if( !userp(target))
                return notify_fail("你不能对NPC使用此内功效果，想用bug牟利啊，没门!\n");

        if ((int)me->query_skill("jiayiforce", 1) < 180)
                return notify_fail("你的嫁衣神功修为还不够。\n");

        if( (int)me->query("force") < 500 ) 
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("kee") < 500 ) 
                return notify_fail("你的气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");

        if( (int)target->query_temp("jiayi_powerup"))
                return notify_fail(target->query("name")+"的体内已经流动着嫁衣神通的真气了。\n");

        if (target==me) {
                message_vision( HIY 
        "$N身形微展，一股真气流遍全身，顿时精芒四射，天地间弥漫着一股逼人的杀气！\n" NOR, me);
        me->add("force", -500);
        me->receive_damage("kee", 500);
        }else {
                message_vision( HIY + 
        "$N身形微展，将一股真气注入$n的体内，$n顿时觉得自己充满了斗志和力量！！\n" +NOR, me, target);
        me->add("max_force", -1);
        me->set("force", 0);
        }

        skill=me->query_skill("jiayiforce",1);

        target->add_temp("apply/attack", skill/3);
        target->add_temp("apply/dodge", skill/3);
        target->set_temp("jiayi_powerup", 1);
        target->start_call_out( 
        (:call_other, __FILE__, "remove_effect",target, skill/3 :), skill/2);

        return 1;
}

remove_effect(object me, int amount)
{
        if ( (int)me->query_temp("jiayi_powerup")){
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("jiayi_powerup");
        tell_object(me, HIR"你体内的嫁衣神通的真气渐渐的消逝，行至丹田，已化于无形……\n"NOR);
        }
}


