// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if ( duration < 0 ) return 0;
	me->apply_condition("relieve_sheng_si", duration - 1);
        me->save();
	return 1;
}
