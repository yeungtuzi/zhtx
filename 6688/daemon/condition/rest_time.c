// rest_time.c

#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("rest_time", duration - 1);
        return 1;
}

