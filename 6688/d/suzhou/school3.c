// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;
void void_sense(object who, int stage);
string *make_msg = ({
	YEL"你意守丹田，敛气上行，渐渐进入一种玄妙的境界。\n"NOR,
	YEL"你只觉得丹田有一股热气上升，沿着任督二脉运行。－－－－－－－\n"NOR,
	YEL"不知道过了多久，你气收丹田，慢慢起立，直觉得全身气血充盈，\n"NOR,
	YEL"潜能有了提高。\n"NOR,	
});

void create()
{
	set("short", BLK"精进楼"NOR);
	set("long", @LONG
		你踏着古老的木梯来到三楼，只见几个趟子手正在专心地修炼
(xiulian)，来往的人怕打扰了他们，不由放轻了脚步。这儿不再有书籍，但墙
上刻有武功招式，看上去变化万千，引人入胜。
LONG
	);
	set("objects",([
	__DIR__"npc/fighter6" : 1,
	]));
	set("exits",([
	"down" : __DIR__"school2",
	]));

	setup();
}

void init()
{
	add_action("do_xiulian","xiulian");
}

int do_xiulian()
{
	object me=this_player();
	int my_exp,my_sen,my_mana,my_int;

	my_exp=me->query("combat_exp");
	my_sen=me->query("sen");
	my_mana=me->query("mana");
	my_int=me->query("int");
	if( me->is_fighting() )
		return notify_fail("你在战斗中，怎么能静下心来修炼呢？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完！\n");
	if( me->query("sen")<=100)
		return notify_fail("你的神太低了，不能静下心来修炼。\n");
	if((int)me->query("potential")>=200)
		return notify_fail("你的潜能已经达到你修炼的上限了。\n");
	if(random(100)>=10 )
	{
		me->start_busy(40);
		call_out("void_sense",1,me,0);
			return 1;
	}  	
	me->start_busy(10);
	me->receive_damage("sen",my_sen*4/5);
	me->add("mana",-my_mana*10/10);
	tell_object(me,RED"你气息纷乱，有一种恶心的感觉，大概是操之过急了。\n"NOR);
		return notify_fail("顿时你动弹不得。。。。。\n");
}

void_sense(object who, int stage)
{
	object me=this_player();
	int my_exp,my_sen,my_mana,my_int;

	my_exp=me->query("combat_exp");
	my_sen=me->query("sen");
	my_mana=me->query("mana");
	my_int=me->query("int");

	tell_object(who, make_msg[stage]);
	if( ++stage < sizeof(make_msg) )
	{
	call_out("void_sense", 10, who, stage );
        	return;
	} 
	me->add("potential",my_exp*1/50000+my_int*1/3+random(10));
	me->add("mana",-my_mana*9/10);
	me->start_busy(5);
	me->receive_damage("sen",my_sen*1/2+random(30));
}
	
