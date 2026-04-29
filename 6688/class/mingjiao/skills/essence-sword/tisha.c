// tisha.c
//By masterall
#include <ansi.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;
int judge(object me,object victim)
{
        int level,mp,dp;
        level = me->query_skill("essence-sword",1); 
        mp = level*level*level; 
        dp = victim->query("combat_exp")*victim->query("cps")/30;
        //和对方的经验和先天定力有关。
        if( random(mp+dp)>dp )
                        return 1;
                else return 0;
}

int perform(object me, object target)
{
        string msg;
        int skill,i,count;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");

        skill= (int)me->query_skill("essence-sword",1);

        if( !me->is_fighting ())
                return notify_fail("「万里黄沙」只能对战斗中使用。\n");

        if( !target ) target = offensive_target(me);

        if( target->query_temp("weapon") )
        tweapon = target->query_temp("weapon");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「万里黄沙」只能对战斗中的对手使用。\n");

//        if( target->is_busy() )
//                return notify_fail(target->name() + "双目难睁，无法攻击。\n");

        if( me->query_skill_mapped("force") != "moni-xinfa")
                return notify_fail("你所用的内功不符合浣花淬玉剑阴戾狠毒的特点！\n");
        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="sword" )
                return notify_fail("「万里黄沙」必须手中有剑。\n");
        
        if( me->query_skill_mapped("sword") != "essence-sword" )
                return notify_fail("只有浣花淬玉剑才可以使用「万里黄沙」。\n");

        if( me->query_skill_mapped("parry") != "essence-sword" )
                return notify_fail("只有浣花淬玉剑才可以使用「万里黄沙」。\n");

                
        if( (int)me->query_skill("essence-sword", 1) < 50 )
                return notify_fail("你的浣花淬玉剑不够娴熟，不会使用「万里黄沙」。\n");

        if( (int)me->query("force") < 2000 )
                return notify_fail("你的内力不够，不能使用「万里黄沙」。\n");

        msg = HIY "$N的身形如旋风般急转了起来，"+weapon->name()+HIY"从地面划起一道道飞沙，\n好比"+HIC"大漠孤烟"+HIY"，又似"+HIR"长河落日"+HIY"，强大的气旋卷起的沙尘铺天盖地般的向$n席卷而来！\n"+HIG"而$N却有如九天仙女下凡一般从半空中轻飘飘落下，衣洁如新，面娇如玉，\n"+HIB"单是这样的场景，已让$n看得呆了........！！\n\n"NOR;
        me->add("force",-300);
        me->start_busy(1);
            if(judge(me,target))
            {

                if( random(me->query("force")) /2> (int)target->query("force") )//对手内力实在太低，直接破内力，受内伤，基本也就不用怎么打了。
                  {
                msg += HIR"\n$n感到迎面而来的狂沙劲风透骨，体内的真气实在无法抵御，\n被冲击波一般的气流撞得像一根稻草般飞了出去！！\n" NOR;
                message_vision(msg, me, target);
                target->set("force",0);
                target->receive_damage("kee",target->query("max_kee")/2+300);
                target->receive_wound("kee",target->query("max_kee")/2+300);
                COMBAT_D->report_status(me,target,1);   
                  }
                else if( target->query("gender")== "男性" && me->query("force_factor") > 100 )//男性遇到这种情况还是要考察一下后天定力
                  {
                msg += HIY"\n$n情知来者不善，但在漫天风沙中看到$N婀娜的体态和娇媚的身姿，\n"+HIC"不由得心驰神往，虽有邪欲，却又觉得$N庄严圣洁丝毫不可亵渎，\n"+HIR"临敌危急时哪容得$n这般思量，举棋不定间，$n只觉得脚下颇为滞涩，\n原来已被席卷而来的沙尘灌了个结结实实！！！\n\n" NOR;
                message_vision(msg, me, target);
                target->start_busy(skill/20+1);
                target->add_temp("apply/attack",-1*skill/2);
                target->add_temp("apply/dodge",-1*skill/2);
                  } else
                  {
                msg += HIY"$n急欲纵身闪开，无奈袭来的沙尘已不容其有躲避的空间，\n"+HIW"$n只觉得自己卷入一股强大地漩涡中，前不能进，后不能退，\n"+HIG"而每一次进退维谷之间，都被$N以雷鸣电闪般的速度攻了一招！！\n\n" NOR;
                message_vision(msg, me, target);
                me->add_temp("apply/attack",skill/2);
                count = (skill- random(target->query_cps()*2))/2;//剩下就等着被连击吧，但连击次数和对方的先天定力有关。
                if( count < 2 ){count=2;}
                if( count >16 ){count=16;}
                if(target)
                for(i=0;i<count;i++)
                    {
                    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
                    }
                me->add_temp("apply/attack",-skill/2);

                  }


           } else {
                if( random(target->query("force"))/2 > me->query("force") ){ //对手内功实在太强。
                msg += HIW"$n体内的真气本能的迸发出来，一股震天撼地的激波将漫天的尘沙都击散了，\n非常规则的散落在$n的四周，\n"+HIR"$N花容失色，腰肢摇曳，不由得“"+HIG"嘤咛"+HIR"”了一声，\n"+HIM"待想再起沙尘，却发现有些真气不纯，力不从心了。\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(5);
                me->add("force",-1000);
                }else if( random(target->query_skill("sword")) > me->query_skill("sword") && target->query_temp("weapon")) {//对手的剑法很高
                msg += HIG"$n手中的"+tweapon->name()+HIG"舞出了一道无边的剑幕，\n"+HIW"缤纷而至的沙尘犹如撞上了以一面坚不可摧的石壁，顿时灰飞烟灭，荡然无存。\n"+HIM"与此同时"+tweapon->name()+HIM"去势未消，中宫疾进，直取$N胸前数大要穴！\n" NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(target, me, tweapon);
                me->start_busy(4);
                }else {//剩下就是一般人
                msg += HIC"$n见其势凶猛，不敢硬接，一声长啸，已然翻身在数丈开外！\n斜睨着$N冷冷一笑，目光中对此卑劣行径颇有不屑之意。\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(3);
                }
        }
   //     message_vision(msg, me, target);

        return 1;
}




