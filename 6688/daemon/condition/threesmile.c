// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{

        if(duration<0){ 
		tell_object(me, HIG"你全身突然感到一阵从所未有的畅快，忍不住哈哈大笑起来。\n"NOR);
		message_vision(HIY"$N：“哈哈哈。。。。。。”\n"NOR, me);
		me->receive_wound("kee", me->query("max_kee") + 1);
		return 0;
	}
			
        me->apply_condition("threesmile", duration - 1);
	if( duration % 3 == 0 )
		tell_room(environment(me), HIY+me->name()+"突然诡异地笑了笑。\n"NOR, me);
        return 1;
}
