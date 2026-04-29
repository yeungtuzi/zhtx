//room_tax.c            
//written by tang

#include <ansi.h>

int update_condition(object me, int duration)
{                
	if( duration < 1 ) return 0;       
                                                                                      
	if( me->query("deposit")>5 )
	{                                                
		if( me->query("tax/delay") )	me->delete("tax/delay");
		me->add("deposit", -5);     
		me->apply_condition("room_tax", duration - 1);
		return 1;
	}

	tell_object(me,"你钱庄的存款不够交房产税啦，快去存钱，否则要没收房产啦。\n");
	me->add("tax/delay", 1);

	if( me->query("tax/delay")>20 )
	{
		if( file_size("/data/room/"+me->query("room/id")+".c")>0 )
		{
			rm("/data/room/"+me->query("room/id")+".c");
			tell_object(me, HIR "由于你迟交房产税，你在开封的住房被没收啦。\n"+ NOR );
			me->delete("room");

			if( present("indenture",me) )	destruct(present("indenture",me));
		}                                           
		me->apply_condition("room_tax", 0);	    
		me->delete("tax/delay");
		return 1;
	}

	return 1;
}