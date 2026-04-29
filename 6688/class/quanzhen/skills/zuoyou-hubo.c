//左右互搏
//write by hacky

#include <ansi.h>

inherit NPC;

int perform(object me, object target)
{
        string msg;
        object weapon;
        if(!me->query("zuoyou-hobo"))
                return notify_fail("你所使用的外功中没有这项功能");                        
        if( !target ) 
		return notify_fail("你要攻击谁。\n");

        if(me->query_temp("weapon")|| me->query_temp("secondary_weapon") )
                return notify_fail("用左右互搏必须空手. \n");
        
	if( me->query_skill_mapped("cuff")!="kongming-quan")
		return notify_fail("你必须使空明拳才能施展「左右互搏」。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「左右互搏」只能对战斗中的对手使用。\n");
        
	if( (int)me->query("force") < 150)
		return notify_fail("你的内力不够，无法施展「左右互搏」。\n"); 

        if( (int)me->query("int") > 20 )
                return notify_fail("你无法分心二用. \n");
        me->add("force", -50);

        msg = CYN "$N使出「左右互搏」，两手各使一着空明拳,闪电般功向$n。\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("kee") < 0 ) 
                return 1;

        
}
