//独孤九剑破剑式
//by Emote 5/20/2000
#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
        int skill,lvl,damage,ap,dp;
        object ob;

        if( !me->is_fighting() )
                return notify_fail("「总诀式」只能在战斗中施用。\n");   
                             
        if( me->is_busy())
                return notify_fail("你正忙着呢，来不及用独孤九剑。\n");

        if( me->query("force") < 1000)
                return notify_fail("你的内力不够，用不了独孤九剑。\n"); 

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使用独孤九剑的「总诀式」。\n");     
         
        if( !target || target == me ) target = offensive_target(me);

        skill = me->query_skill("dugu-jiujian",1);

        
        if( skill < 250 ) return notify_fail("你的「独孤九剑」招式不够娴熟，使不出「总诀式」。\n");   
        if( me->query_skill("sword",1)<250) return notify_fail("你的基本剑术不够扎实，无法使用「总诀式」。\n");
        if( me->query_skill("blade",1)<250) return notify_fail("你的基本刀法不够扎实，无法使用「总诀式」。\n");
        if( me->query_skill("throwing",1)<250) return notify_fail("你的暗器使用不够扎实，无法使用「总诀式」。\n");
        if( me->query_skill("spear",1)<250) return notify_fail("你的基本枪法不够扎实，无法使用「总诀式」。\n");
        if( me->query_skill("strike",1)<250) return notify_fail("你的基本掌法不够扎实，无法使用「总诀式」。\n");
        if( me->query_skill("whip",1)<250) return notify_fail("你的基础鞭术不够扎实，无法使用「总诀式」。\n");
        if( me->query_skill("force",1)<250) return notify_fail("你的内功心法不够扎实，无法使用「总诀式」。\n");
        if( me->query_skill("zong-jue",1)<300) return notify_fail("你的总诀式不够扎实，无法使用「总诀式」。\n");
        message_vision(HIY"$N使出"+HIR"独孤九剑"+HIY"「总诀式」，静气凝神，仔细观察$n的一举一动，试图找出$n的破绽.\n" NOR, me,target);
        me->add("force", -1000);

        lvl = skill + me->query_skill("zong-jue",1)/2;
        ap  = (lvl*lvl/100)*lvl;//和自己sword等级
        dp  = target->query("combat_exp")/100;//对方也是一样
        if( target->query("id") == "buzhi huowu" ) ap = ap*2/3;
        if( target->query("id") == "long xiang" ) ap = ap*2/3;

        if( random(ap) > dp){
        message_vision(HIY"\n$N眼中灵光一闪，找出了$n的要害之处...\n"NOR,me,target);  
        message_vision(HIR"\n只见$N挺剑刺出，正中$n的最薄弱之处。\n"NOR,me,target);

        damage = me->query_skill("sword")+me->query_skill("dugu-jiujian",1); 
        damage += me->query("force_factor");

                if(objectp(ob=target->query_temp("weapon")) )
                {
                ob = target->query_temp("weapon");
        message_vision(HIG"$n只觉得手腕一阵酸麻，"  + ob->name() + HIG "再也拿捏不住，脱手飞出！\n\n"NOR,me,target);
                ob->unequip();
                ob->move(environment(target));
                }

        if( !userp(target) ) damage *= 3;
        target->receive_wound("kee",damage,me);
        COMBAT_D->report_status(me,target,1);                   
        target->set("force_factor",0);
        target->reset_action();
        target->set_temp("bepo",1);
        me->start_busy(2);

        }else{
        message_vision(HIW"\n$N实在无法发现$n的要害之处，只得收起剑式，此时动作已然有些不大灵光。\n"NOR,me,target);
        me->start_busy(5);
        }

        return 1;
}

