// /daemon/class/lama/space/seeheart.c

#include <ansi.h>

inherit F_CLEAN_UP;
inherit SSERVER;

int conjure(object me, object target)
{
	int myexp, yourexp, i;
	string msg;

	if( !target ) return notify_fail("你要查看谁的心灵?\n");
	if( target==me) return notify_fail("查看自己?用hp比较准些.\n");
	if( !living(target)) return notify_fail("没必要查.\n");
	if( (int)me->query("atman") < 5 ) 
		return notify_fail("你的灵力不够！\n");

	myexp=me->query("combat_exp");
	if(!myexp) return notify_fail("你的经验不足,什么也别想看到.\n");
	yourexp=target->query("combat_exp");
	tell_object(target, "好象有人偷偷地看了你一眼.\n");
	me->add("atman", -5);

	i=(int)yourexp/myexp;
	if(i>=200) msg = NOR +"一塌糊涂"+ NOR;
	if(i<200) msg = HIC +"神秘莫测"+ NOR;
	if(i<50) msg = HIC +"比你强太多了"+ NOR;
	if(i<10) msg = HIY +"比你强多了"+ NOR;
	if(i<5) msg = HIY +"比你强些有限"+ NOR;
	if(i<2) msg = GRN +"普普通通"+ NOR; 
	if(i<1) msg = GRN +"什么也不会"+ NOR;
	tell_object(me,"这家伙看上去"+msg+"\n");
	return 1;
}
