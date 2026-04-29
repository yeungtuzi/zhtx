// finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
                 if( (int)me->query("sen") < 60 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) && !raw_wiz_level(me) ) {
			me->receive_damage("sen", 50);
                    me->start_more( FINGER_D->finger_all() );
		} else
                    me->start_more( FINGER_D->finger_allw() );
	} else {
                if( (int)me->query("sen") < 60 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) && !raw_wiz_level(me) ) {
			me->receive_damage("sen", 15);
                    me->start_more( FINGER_D->finger_user(arg) );
		} else
                    me->start_more( FINGER_D->finger_userw(arg) );
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : finger [使用者姓名]
 
这个指令, 如果没有指定使用者姓明, 会显示出所有正在线上玩家
的连线资料. 反之, 则可显示有关某个玩家的连线, 权限等资料.
 
see also : who
HELP
    );
    return 1;
}
 
