// sleep.c

int update_condition(object me, int duration)
{

        if (duration < 1) 
	{
		me->treasure_destruct();
		return 0;
	}

	me->apply_condition("treasure_move", duration-1);

	if( duration%20 == 0 )	
		me->treasure_move();

        return 1;
}
