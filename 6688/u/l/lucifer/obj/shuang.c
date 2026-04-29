//月冷如霜,寒雪鞭法

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int mjianb, mjianh, tparryb, tparryh, mneili, tneili, mexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        mjianb= (int)me->query_skill("whip",1);
        mjianh= (int)me->query_skill("snowwhip",1);
        mneili = (int)me->query("force");
        mexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="whip")
                return notify_fail("不拿鞭子怎使「月冷如霜」?\n");
        if(me->query("family/family_name")!="晚月派")
                return notify_fail("你不是晚月弟子，使不出这招！\n");
        if ( mjianh < 80) return notify_fail("你的寒雪鞭法还不够火候！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「月冷如霜」只能在战斗中使用。\n");
        if ((int)me->query("force")<300)
                return notify_fail("你的内力不够。\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tneili = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-200);
        me->receive_damage("sen", 20);
        
     message_vision(HIC"$N招式一变，手中"+weapon->name()+HIC"斜弯向下，双眸蓝影森然，寒意神功蓄势待发，好一式晚月绝学--「月冷如霜」！\n\n" NOR,me,target);        
     message_vision(HIM"$N向前缓步一踱，浑身的衣服无风自鼓，劲力已然直透鞭稍，只见$N手中的"+weapon->name()+HIM"如毒蛇吐芯般昂头前行，如霜的寒意神功已然逼近肌肤！！！\n\n"NOR,me,target);
     message_vision(HIM"这一招「月冷如霜」着实狠辣。\n\n"NOR,me);
     if (random(mexp)>(int)(texp/10) && random(mneili) > (int)(tneili/3)&&
          (int)me->query("max_force")+mneili > (int)target->query("max_force") + tneili) 
        {
             msg = HIC"$n只觉得一股寒气象化作千百枚细针一样，穿体而过！\n"
                                "“哇”的一声，$n喷出一大口鲜血，脸色也随之成了霜白，看来是受了内伤！\n\n"NOR;
     damage= (int)(((int)me->query("max_force")-  (int)target->query("max_force")/2)/3);
     if(damage<1)damage = 1;
     target->receive_damage("kee",damage*2, me);
     target->receive_wound("kee", damage*2/3, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else {
           msg = HIC"$n忙运功与之相抗，深厚的内力将$N的漫天鞭影和无边的寒意都激散了。\n\n"NOR;
           message_vision(msg, me, target);
        }

     message_vision(HIM"$N由缓趋疾，鞭走奇锋，每一鞭从$n意想不到的方位冷若冰霜地挥出！\n" NOR,me,target);
     message_vision(HIM"这一式鞭法犹如寒霜骤降，令人措手不及！\n\n" NOR,me,target);
     if(random(mexp*2)>(int)(texp/10)&& random((int)(mjianb + mjianh*3))>(int)((tparryb+tparryh)/2))
     {
             msg = HIC"$n被鞭风一荡，头脑都似乎被冻僵了，不知该如何去招架这似雷、似电又似风的鞭法！\n"
     "果不其然，$N的"+weapon->name()+HIC"招招击中要害，$n浑身上下被一道道寒霜似的鞭锋给抽得遍体鳞伤！\n\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", damage*2, me);
     target->receive_wound("kee", damage*2/3, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
          msg = HIC"$n却心如止水，以快制快，身形飘忽间就脱出了$N这凌厉的攻势。\n\n"NOR;
          message_vision(msg, me, target);
        }


          message_vision(HIM"$N突然自满天鞭影之中立住身形，鞭身一颤，随即一个斜身，似被自身的鞭子拌了个踉跄。\n"NOR,me);
          message_vision(HIM"这一式端地巧妙！\n\n"NOR,me);
          if(random(mexp)>(int)(texp/2))
          {
                msg = HIC"$n果不其然，以为$N已为己所伤，急忙探身上前抢攻。\n"
          "不料$N微微一笑，待$n靠近，寒意功急如闪电，鼓动鞭锋，直探$n的胸口。\n"
          "$n连鞭影还没看到，就差点儿被穿了一个透心凉！\n\n"NOR;
          damage=(int)(random((int)(mjianh/2))+me->query("force_factor")*3/2);
          if(damage<1)damage = 1;
          target->receive_damage("kee", damage*2, me);
          target->receive_wound("kee", damage*2/3, me);
          message_vision(msg, me, target);
          COMBAT_D->report_status(target);
     }
     else{
          msg = HIC"$n早就看破了这招的虚实，假意前冲，却在$N出招的一瞬间回手反攻一招！\n\n"NOR;
          message_vision(msg, me, target);
          COMBAT_D->do_attack(target, me, tweapon);
        }
        
       me->start_busy(1);
           
        return 1;
}

