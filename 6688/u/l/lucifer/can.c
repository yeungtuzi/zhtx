 // can.c 般若残生掌

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // int skill;
        // 2026-04-30: unused variable commented out
        // string weapon;
        int damage;
        string *limb, type, result, str;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("般若残生掌只能在战斗中使用。\n");

        if( me->query_temp("weapon") )
                return notify_fail("你只能在空手时使用般若残生掌！\n");

        if( me->query("betrayer")>0 )
                return notify_fail("背叛师门的人怎么能使用少林绝技?\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("你所用的并非混元一气功，无法施展般若残生掌！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 120)
                return notify_fail("你的混元一气功火候未到，无法施展般若残生掌！\n");

        if( me->query_skill("banruo-zhang", 1) < 120 )
                return notify_fail("你的般若掌火候未到，无法施展般若残生掌！\n");

        if( me->query("faith", 1) < 2000 )
                return notify_fail("你的门忠不够，还没学会般若残生掌！\n");

        if( (int)me->query_temp("skill_mark/banruo-zhang"))
                return notify_fail("般若残生掌正在运行中！\n");

        if( me->query("max_force") <= 1500 )
                return notify_fail("你的内力修为不足，无法施展般若残生掌！\n");

        if( (int)me->query("force") < 2500  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("max_age") - (int)me->query("age")<10)
        {
        message_vision(WHT "$N狂啸一声：老衲虽已命不久矣，但这般若残生掌还能使出来,施主接招吧!\n"NOR,me);
        }
        else
        {
        message_vision(GRN "$N轻叹一声：阿弥陀佛，看来老衲今天要大开杀界了！\n" NOR, me);
        }
        me->set_temp("skill_mark/banruo-zhang",1);

        message_vision( GRN"$N突然左掌一收假意卖了个破绽，右掌风驰电掣般的扫向$n\n"NOR,me,target);
        if( target->query_skill("dodge")+target->query_skill("parry")* 2/3 < random((me->query_skill("strike") + me->query_skill("force"))*4/3))
        {
                damage = random(((int)me->query_skill("strike"))+me->query("enforce"));
                if(damage > 500) damage = 500;
                if(damage < 200) damage = 200;
                me->add("force", -me->query("enforce")/2);

                target->receive_damage("kee", damage,  me);
                target->receive_wound("kee", (int)me->query_skill("strike"), me);

                limb = target->query("limbs");
                type = "瘀伤";
                message_vision(HIR"$N发出一声闷响，被这排山倒海般的掌力打在$P"+limb[random(sizeof(limb))]+"上，一口淤血从口中溜出。\n"NOR,target);

                str = COMBAT_D->status_msg((int)target->query("kee") * 100 /(int)target->query("max_kee"));
                message_vision("($N"+str+")\n", target);
                if(me->query("age")>=30 )
                {
                remove_call_out("pfm2");
                call_out("pfm2", 3, me, target);
                }
                else
                {
                me->delete_temp("skill_mark/banruo-zhang");
                }
                me->start_busy(1+random(2));
        }
        else if( ( random( target->query_skill("dodge") ) >  me->query_skill("strike")*2/3) && random(3) == 1 )
        {
                message_vision(HIR"$N猛觉得掌风逼来，赶紧运起轻功向上一越，左脚轻轻的点在$n背上，结果$n轻闷一声，似乎受了点伤。\n"NOR, target,me );
                me->receive_damage("kee", 50+random(50),  me);
                me->start_busy(1+random(1));
                str = COMBAT_D->status_msg((int)me->query("kee") * 100 /(int)me->query("max_kee"));
                message_vision("($N"+str+")\n", me);
                me->delete_temp("skill_mark/banruo-zhang");
        }
        else
        {
                message_vision( HIG"$N感觉这一掌来势凶猛，立刻左躲右闪勉强逃过了$n这一招，不过也被累的汗流浃背。\n\n" NOR,  target,me);
                me->start_busy(1);
                me->delete_temp("skill_mark/banruo-zhang");
        }
        me->add("force", -200);
        me->start_busy( 1 );

        return 1;
}
int pfm2(object me, object target)
{
        int t;
        t=(int)me->query_skill("banruo-zhang")+(int)me->query("age");

        if (!me)
        {
        me->delete_temp("skill_mark/banruo-zhang");
        return 1;
        }
        if (!(objectp(present(target->query("id"), environment(me)))))
        {
        me->delete_temp("skill_mark/banruo-zhang");
        return 1;
        }
        if(!living(target))
        {
        me->delete_temp("skill_mark/banruo-zhang");
        return 1;
        }
        me->add_temp("apply/damage", 2*t);
        me->add_temp("apply/attack", 2*t);
        message_vision( HIG"\n紧接着$N飞奔过去,左掌化为蛇型右掌化为虎型,口念大般若经开对准$n胸口发出闪电两击.\n" NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/damage", -2*t);
        me->add_temp("apply/attack", -2*t);
        me->add("force", -50);
        if (me->query("age")>=40 )
        {
        remove_call_out("pfm3");
        call_out("pfm3", 3, me, target);
        }
        else
        {
        me->delete_temp("skill_mark/banruo-zhang");
        }
        return 1;

}

int pfm3(object me, object target)
{
        int t;
        t=(int)me->query_skill("banruo-zhang")+(int)me->query("age");
        if (!me)
        {
        me->delete_temp("skill_mark/banruo-zhang");
        return 1;
        }
        if (!(objectp(present(target->query("id"), environment(me)))))
        {
        me->delete_temp("skill_mark/banruo-zhang");
        return 1;
        }
        if(!living(target))
        {
        me->delete_temp("skill_mark/banruo-zhang");
        return 1;
        }
        me->add_temp("apply/damage", 4*t);
        me->add_temp("apply/attack", 4*t);
        message_vision( HIY"\n掌法运用至此,$N渐渐有所领悟,达摩老祖的教诲浮现在耳旁,向$n攻出少林决学-- 残生三连击.\n" NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/damage", -4*t);
        me->add_temp("apply/attack", -4*t);
        me->add("force", -50);
        if (me->query("age")>=60 )
        {
        remove_call_out("pfm4");
        call_out("pfm4", 3, me, target);
        }
        else
        {
        me->delete_temp("skill_mark/banruo-zhang");
        }
        return 1;

}
int pfm4(object me, object target)
{
        int t;
        t=(int)me->query_skill("banruo-zhang")+(int)me->query("age");
        me->delete_temp("skill_mark/banruo-zhang");
        if (!me) return 1;
        if(!living(target)) return 1;
        if (!(objectp(present(target->query("id"), environment(me)))))
        return 1;
        me->add_temp("apply/damage", 6*t);
        me->add_temp("apply/attack", 6*t);
        message_vision( HIW"\n最后,$N惨笑一声:老衲已经命不久矣多杀一人又有何妨,施主归西吧!舍命一击随即发出!!$n.\n" NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/damage", -6*t);
        me->add_temp("apply/attack", -6*t);
        me->add("force", -50);
        return 1;

}

