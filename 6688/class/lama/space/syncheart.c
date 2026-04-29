// /daemon/class/lama/space/syncheart.c
// 同心术

#include <ansi.h>

inherit F_CLEAN_UP;
inherit SSERVER;

int conjure(object me, object target)
{
	int mybel, yourbel, i;
	object *enemy;

//        if( (string)me->query("gender")!="女性")
//                return notify_fail("这不是你能使用的神通!\n");
        if( wizardp(me) )return notify_fail("巫师限制使用此法术!\n");
	if(!target || target==me) return notify_fail("不能对自己.\n");
	if(!living(target)) return notify_fail("没效果\n");
	if((int)target->query("combat_exp")>(int)me->query("combat_exp")*10)
		return notify_fail("少惹这种家伙为妙.\n");
	if( (int)me->query("atman") < 30)
		return notify_fail("你的灵力不够了！\n");
	if( (int)me->query("sen") < 10 )
		return notify_fail("你的精神无法集中！\n");
	me->add("atman", -30);
	me->receive_damage("sen", 10);
	mybel=me->query("bellicosity");
	yourbel=target->query("bellicosity");
	if(me->is_fighting()){
		if(target->query_temp("guarding")==me) {
			yourbel+=me->query_skill("space",1)*10;
			message_vision(HIY"$N受到$n的激励,勇气倍增!\n"NOR,
			target, me);
			target->set("bellicosity", yourbel);
			return 1;
		}
		enemy = me->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if(enemy[i]==target){
				yourbel-=me->query_skill("space",1)*10;
				if(yourbel<1) yourbel=0;
	message_vision(HIY"$N受到$n的刺激,战意低落.\n"NOR,target, me);
			target->set("bellicosity", yourbel);
			return 1;
			}
		}
		return notify_fail("拜托,先打完这架再说!\n");
	}
        i=me->query_skill("zang-buddhi",1);
	if(mybel>i*10) {
		yourbel+=mybel*2;
		message_vision(HIY"$N受到$n的刺激,想要杀人了.\n", target, me);
		target->set("bellicosity", yourbel);
		return 1;
	}
        yourbel-=me->query_skill("zang-buddhi",1);
	yourbel-=me->query_skill("space",1);
	if(yourbel<1)yourbel=0;
	message_vision(HIC"$N得到$n的温言安慰,变得平静多了.\n", target, me);
	return 1;
}
