//死亡的宣告 
//by zephyr
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object doomer;
	doomer = me->query_temp("doomer");
	if( !living(me) ) 
	{
		message("vision", HIB"\n" + me->name() + "眉心的暗黑之气倏地聚集了一下又散开来，但是看上去愈加浓了。\n"NOR, environment(me), me);
	}
	else if ( !present(doomer,environment(me)) )
	{
		return 0;
	}
	else 
	{
		tell_object(me, BLK "你感到眉头之处一紧一松之后，那股压力越来越沉重。\n" NOR );
		message("vision", me->name() + "眉心的暗黑之气倏地聚集了一下又散开来，但是看上去愈加浓了。\n", environment(me), me);
		tell_object(me, BLK "你耳边仿佛有个又阴又冷，仿佛来自地狱的声音对你说：“你只有" + chinese_number( duration ) + "秒钟的时间了。”\n" NOR );
	}
	me->apply_condition("doom", duration - 1);
	if( duration == 1 ) 
	{
		if (userp(me))
			me->unconcious();
		else me->die();
		return 0; 
	}
	if( duration < 1 ) 
		return 0; 

	return CND_CONTINUE;
}
