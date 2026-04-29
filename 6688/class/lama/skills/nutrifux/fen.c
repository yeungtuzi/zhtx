#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int count,skill,tskill; 
        object weapon;                                   
        
        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「烈火焚身」只能在战斗中使用。\n");

        if( (int)me->query("kee") < 500 ) return notify_fail("你的气不够！\n");

        if( me->query_skill_mapped("strike") != "nutrifux" )
                return notify_fail("只有火焰刀才可以使用「烈火焚身」。\n");
        if( me->query_skill_mapped("parry") != "nutrifux" )
                return notify_fail("只有火焰刀才可以使用「烈火焚身」。\n");
        if( (int)me->query("force") <  2500 )
                return notify_fail("你的真气不够！\n");

        skill = me->query_skill("nutrifux",1);
        tskill = target->query_skill("force");

        if( skill < 200 )                              
                return notify_fail("你的「火焰刀」修为太潜！\n");
                
        if( me->query_temp("weapon") )
                return notify_fail("使用「烈火焚身」不能用兵器！\n");

        msg = HIY "\n$N全身真气激荡，随之鼓起的袍袖如熊熊烈火，似冉冉热焰，\n"
                  "$N一宣佛号“我佛慈悲！！”，方圆数丈荡起的劲气好比黄河入海，又如大江东去！\n" NOR;

        message_vision(msg, me, target);
        me->start_busy(3);
        count = ( skill - tskill*2/3 ) / 25;
        if( count < 1 ) count = 1;
        if( count > 9 ) count = 9;

        if( count < 3){
        message_vision(HIC"\n$n爆喝一声，一股澎湃的真气护住了身前数大要穴，\n$N排山倒海的攻势好似撞在一堵墙上，登时无影无踪，消于无形。\n\n"NOR,me, target);
        }else if( count > 2 && count < 8 ){
        message_vision(HIG"\n$n危急间有些手忙脚乱，想运功护体，又想趁势反击，踌躇之间，被$N堪堪攻了个正着。\n\n"NOR,me, target);
        }else{
        message_vision(HIR"\n$n觉得劲气扑面而来，一股股热浪有如火灼一般，好像烈火焚身，脑袋疼得就要炸开了！！\n\n"NOR,me, target);
        }
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();                   
                if( ob ){
                          me->add_temp("apply/attack",skill/10);
                        COMBAT_D->do_attack(me, ob,weapon,TYPE_QUICK);
                        me->add_temp("apply/attack",-skill/10);
                }else
                {
                        message_vision(HIB"\n$N合掌而立，默默的为亡魂超度，嘴角却露出一丝任何人都察觉不到的狞笑。\n"NOR,me);
                        break;
                }
                me->receive_damage("kee", 5);
                me->add("force", -20);
        }
        message_vision(BLK"\n$N将劲气收回体内，方圆数丈则弥漫着浓重的烟气。\n\n"NOR,me);
        me->add("force", -300);
        return 1;
}

