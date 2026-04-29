#include <ansi.h>
#include <combat.h>
//inherit SSERVER;

int exert(object me, object target)
{
        string msg;
        int count,skill_level; 
        object weapon;                                   
	
        if( !me->is_fighting() )
                return notify_fail("「燎原百击」只能在战斗中使用。\n");

        if( (int)me->query("kee") < 500 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") <  500 )
                return notify_fail("你的真气不够！\n");

	skill_level = me->query_skill("liaoyuan-spear",1);
	skill_level += me->query_skill("liaoyuan-force",1);
	
	if( skill_level < 200 )                              
		return notify_fail("你的修为太潜！\n");
		
	if( !(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "spear" || me->query_skill_mapped("spear") != "liaoyuan-spear" )
		return notify_fail("「燎原百击」只能和燎原枪法配合使用！\n");

        msg = HIY "\n$N大喝一声，运起燎原心法，手中"+(me->query_temp("weapon"))->query("name")+"如同神龙般奔腾夭矫。\n"
		  "正是燎原枪法中的极致，「燎原百击」！\n\n" NOR;

        message_vision(msg, me);
        count = skill_level/40+3;
        if( count > 16 ) count = 16;
        while( count-- ) {
                object ob;

                me->clean_up_enemy();
                ob = me->select_opponent();                   
		if( ob )
	                COMBAT_D->do_attack(me, ob,weapon,TYPE_QUICK);
		else
		{
			message_vision(GRN"\n$N含笑收枪而立，似是从未出手。\n\n"NOR,me);
			break;
		}
                me->receive_damage("kee", 5);
                me->add("force", -20);
        }
        me->start_busy(3);
        return 1;
}

