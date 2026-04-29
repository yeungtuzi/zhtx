/**************************************************************************/
/// $Id: make_music.c,v 1.2 2000/12/14 15:21:43 cmy Exp $
/**************************************************************************/
// music.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg1,msg2,msg3,msg4;
        string weapon;
        int imusic;
        int imakeing,ilvl,iratio;
        int target_kee,current_kee,eff_kee;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("高山流水只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");
        if(weapon!=0) return notify_fail("你必须空手才能用高山流水\n");

        imusic = me->query_skill("music",1);
        imakeing = me->query_skill("tie_makeing",1);
        ilvl = imusic/200+imakeing/200+1;
        if(ilvl>5) ilvl=5;        

        if(imakeing < 201) return notify_fail("你的鬼斧神工还不到家，无法很快作出乐器来伤敌。\n");
        if(imusic < 301) return notify_fail("你的丝竹之技还不够火候，无法弹出高山流水.\n");

        if( me->query_skill_mapped("unarmed") != "tie_makeing")
                return notify_fail("你必须首先激发鬼斧神工!\n");

        if( (int)me->query("kee") < 500 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") - (int)me->query("max_force") < 100 )
                return notify_fail("你的真气不够！\n");


        target_kee  = target->query("max_kee");
        current_kee = target->query("kee");
        eff_kee     = target->query("eff_kee");

        if(eff_kee < target_kee/15*ilvl+10) return notify_fail("对方已经伤心成这样，就不要再去伤害人家了吧。\n");
        target->receive_damage("kee",100);
        target->receive_wound("kee",target_kee/15*ilvl+10);
        me->start_busy(6);

        msg1 = CYN "$N从地上捡起一个石块，双掌合住，$n只见石屑纷飞，很快$N居然多了一个石头做的古筝！！！\n",
        msg2 = MAG "$N左手执筝，右手五指连挥，竟然单手谈出一曲「高山流水」！\n"NOR;
        msg3 = MAG "$n想起因为追求武道而遭冷落的远方的爱人，心中不由的一阵剧痛。\n"NOR;
        msg4 = HIR "$n哇的一声吐出一口鲜血，看来受了很严重的内伤！\n"NOR;

        message_vision(msg1, me, target);         
        message_vision(msg2, me, target);         
        message_vision(msg3, me, target);         
        message_vision(msg4, me, target);         
        me->add("force",-300);
        return 1;
}

