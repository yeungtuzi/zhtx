// /daemon/class/lama/space/protect.c
// 佛光普照
//

#include <ansi.h>

inherit F_CLEAN_UP;
inherit SSERVER;

void remove_effect(object me, int amount);

int conjure(object me, object target)
{
	int skill;
        if( wizardp(me) )return notify_fail("巫师限制使用此法术!\n");
	if( !target) target=me;
	if( !target || !target->is_character() || target->is_corpse())
		return notify_fail("你只能保护活物!\n");
        if( !userp(target))
                return notify_fail("你不能对NPC使用此神通，想用bug牟利啊，没门!\n");
	if( (int)me->query("atman") < 50 ) 
		return notify_fail("你的灵力不够！\n");
	if( (int)me->query("sen") < 50)
		return notify_fail("你的神不够！\n");
	if( (int)target->query_temp("protected"))
		return 
		notify_fail(target->query("name")+"已经受到佛光的保护了.\n");
	if (target==me) {
		message_vision( HIY 
	"$N低诵六字真言,一层淡金色的光辉笼罩了自己全身....\n" NOR, me);
	}else {
		message_vision( HIY + 
"$N低诵六字真言,一层淡金色的光辉泛起,渐渐地笼罩在$n的身上....\n" +
NOR, me, target);
	}
	me->add("atman", -50);
	me->receive_damage("sen", 50);
	skill=me->query_skill("space",1)+me->query_skill("magic",1)+
                me->query_skill("zang-buddhi", 1);

	if( random(me->query("max_atman")) > 120 || skill > 150) {
		target->add_temp("apply/armor", skill*2);
                target->add_temp("apply/defense", skill/15);
		target->set_temp("protected", 1);
		target->start_call_out( 
		(:call_other, __FILE__, "remove_effect",target, skill*2 :), 
		skill/2);
	}
        else
                me->unconcious();
        if( me->is_fighting() )
                me->start_busy(random(5));
        return 1;
}

remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("protected")){
	me->add_temp("apply/armor", - amount);
        me->add_temp("apply/defense", -amount/30);
	me->delete_temp("protected");
	tell_object(me, "笼罩在你身上的佛光渐渐散去,一切恢复如常.\n");
	}
}
