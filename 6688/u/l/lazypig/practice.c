// practice.c

#include <ansi.h>
#define ALL_COST -10000
#define ONE_COST -1000

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skillname;
	int skill, skill_basic,point,times=0,rest_kee;

	seteuid(getuid());

	if(!arg) return notify_fail("请用 help practice 查看其用法。\n");

	if(sscanf(arg,"%s with all",arg)==1)  point=ALL_COST;
	else if(sscanf(arg,"%s with %d",arg,point)==2)
	{
		if(point <= 0 ) return notify_fail("你不是开玩笑吧.\n");
		if((rest_kee=me->query("kee")-point) < 0 ) return notify_fail("你没有这么多气。\n");
	}
	else point=ONE_COST;

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
	if( me->is_busy() )
		return notify_fail("你正忙著做其他事！\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像还没「学会」这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");

	notify_fail("这项技能不能用练的。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("你试著练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");

	if(point==ONE_COST){
		if( SKILL_D(skillname)->practice_skill(me) ) times=1;
	}
	else if(point==ALL_COST){
		while(1){
			if( SKILL_D(skillname)->practice_skill(me) ) times += 1;
			else break;
		}
	}
	else{
		while(1){
			if( SKILL_D(skillname)->practice_skill(me)
				&& me->query("kee") > rest_kee ) times += 1;
			else break;
		}
	}
	if( times > 0 ) {
		me->improve_skill(skillname, times*(skill_basic/5 +1), (skill_basic - 20 > skill && (!me->query("betrayer")||skill<150) )? 0: 1);
		if(!(int)me->query("env/message_brief"))
			write( HIY "你的" + to_chinese(skillname) + "进步了！\n" NOR);
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@TEXT
指令格式：

practice <技能种类>                   : 逐次地联。
practice <技能种类> with <神的点数>   : 指定需耗气的点数。
practice <技能种类> with all          : 耗全部的气。

这个指令让你练习某个种类的技能，这个技能必须是经过 enable 的专业技能。

如果你对这方面的基本技能够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出於蓝胜於蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。
TEXT
	);
	return 1;
}
