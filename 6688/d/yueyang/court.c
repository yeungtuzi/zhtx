// Room: /d/yueyang/court.c
// Tang

#include <ansi.h>

int bonus(object man,int exp)
{
	object ob;

	tell_object(man,"你举报有功，现对你的行为给予奖励！这只是象征性的，请笑纳。\n");
	if( exp>2000000 )	exp=2000000;
	man->add("combat_exp",exp/10000);
	ob=new("/obj/money/gold");
	ob->set_amount(1);
	ob->move(man);

	return 1;
}


inherit ROOM;

void create()
{
	set("short", "法庭");
	set("long", @LONG
这是纵横天下的法庭，你可以在这检举（accuse）他人的不法行为，
举报成功者可获得相应的奖励，被举报者将送到那个特别 cool 的监狱，
并受到相应的惩罚。举报者请在钱庄存入 1 gold 作为诉讼费。目前有
“滥杀无辜(massacre)”(即大量屠杀 npc)，“谋杀(murdur)”(即多
次 pk)和“利用bug牟利(bug)”三类罪行。
LONG
	);

	set("no_magic",1);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"xidajie1",
	]));


	setup();
}

void init()
{
	add_action("do_accuse","accuse");
}

int do_accuse(string arg)
{
	string target,crime;
	int combat_exp,age,n,exp=0,lost_exp,lost_gold;//add by pock,record to log file
	
	object me,who,room;

	me=this_player();
	room=load_object("/d/yueyang/court");

	if( room->query("is_busy") )
		return notify_fail("请稍等！\n");

	if( me->is_busy() )
		return notify_fail("你正忙着呢！\n");

	if( !arg || sscanf(arg,"%s of %s",target,crime)!=2 )
		return notify_fail("accuse sb of sth\n");

	me=this_player();

	if( age=me->query("age")<18 )
		return notify_fail("你成年后再来打官司吧！\n");
	if( combat_exp = me->query("combat_exp")<200000)
		return notify_fail("你在江湖上毫无名气，现在官府不会理你的！\n");

	if( me->query("deposit")<10000 )
		return notify_fail("衙门八字朝外开，有理没钱莫进来！\n");

	if( !who=find_player(target) )
		return notify_fail("你弄清楚是谁再来吧！\n");
	
	if( wizardp(who) )
		return notify_fail("你弄错了，"+who->name()+"是个巫师！\n");

	if( file_name(environment(who))=="/d/wizard/jianyu" )
		return notify_fail(who->name()+"正在狱中。\n");

	age=who->query("age");
	me->start_busy(2);
	me->add("deposit",-10000);

	room->set("is_busy",1);

	switch( crime )
	{
	case "滥杀无辜":
	case "massacre":
		n=(age-13)*300;
		if( who->query("MKS")>n && random(2) )
		{
			who->set("MKS",n);
log_file("ACCUSE_LOG",sprintf("(%s) %s accuse %s of 滥杀无辜\n", 
	ctime(time()), me->query("id"),who->query("id")));
			who->set("combat_exp",(age-13)*150000);

			break;
		}
		me->add_condition("bonze_jail",150);
		tell_object(me,"你诬告他人，判入狱半小时。\n");
		me->move("/d/wizard/jianyu");
		room->delete("is_busy");
		return 1;

	case "谋杀":
	case "murdur":
		n=(age-13)*2;
		if( who->query("PKS")>n && random(who->query("PKS")) > 1 )
		{
			who->set("PKS",n);
log_file("ACCUSE_LOG",sprintf("(%s) %s accuse %s of 谋杀\n", 
	ctime(time()), me->query("id"),who->query("id")));
			break;
		}
		me->add_condition("bonze_jail",150);
		tell_object(me,"你诬告他人，判入狱半小时。\n");
		me->move("/d/wizard/jianyu");
		room->delete("is_busy");
		return 1;

	case "利用bug牟利":
	case "bug":
		exp=who->query("combat_exp");

		if( exp>(age-13)*150000 && age<35 )//每年增加 150000 exp
		{
			lost_exp=exp-(age-13)*150000;
log_file("ACCUSE_LOG",sprintf("(%s) %s accuse %s %s lost %d exp\n", ctime(time()), me->query("id"),who->query("id"),who->query("id"),lost_exp));
			who->set("combat_exp",(age-13)*150000);
			break;
		}

		if( who->query("deposit")>(age-13)*3000000 )//每年增加 300 gold 积蓄
		{
			lost_gold=(who->query("deposit")-(age-13)*3000000)/10000;
log_file( "ACCUSE_LOG", sprintf("(%s) %s accuse %s %s lost %d golds\n", ctime(time()), me->query("id"),who->query("id"),who->query("id"),lost_gold));
			who->set("deposit",who->query("deposit")*9/10);
			break;
		}
		
		if( who->query("str")>who->query_skill("force",1)/4 
			&& who->query("str") >55 )
		{
			who->set("str",55);
log_file("ACCUSE_LOG",sprintf("(%s) %s accuse %s because str\n",
		 ctime(time()),me->query("id"),who->query("id")));
			break;
		}
		
		if( who->query("int")>who->query_skill("literate",1)/4 
			&& who->query("int") >55 )
		{
			who->set("int",55);
log_file("ACCUSE_LOG",sprintf("(%s) %s accuse %s because int\n",
		 ctime(time()),me->query("id"),who->query("id")));

			break;
		}
		if( who->query("con")>(who->query_skill("force",1)/4+1) 
			&& who->query("con") >55 )
		{
log_file("ACCUSE_LOG",sprintf("(%s) %s accuse %s because con\n",
		 ctime(time()),me->query("id"),who->query("id")));
			who->set("con",56);
			break;
		}

		if( who->query("kar")>36 )
		{
log_file("ACCUSE_LOG",sprintf("(%s) %s accuse %s because kar\n",
		 ctime(time()),me->query("id"),who->query("id")));
    		who->set("kar",36);
			break;
		}

		tell_object(me,"你诬告他人，将受到惩罚。\n");
		me->move("/d/oldpine/pine1");
		room->delete("is_busy");
		return 1;

	default:
		room->delete("is_busy");
		return notify_fail("目前只有'滥杀无辜'，'谋杀'和'利用bug牟利'三种罪行。\n");
	}
	bonus(me,exp);
	who->add_condition("bonze_jail",150);
	who->move("/d/wizard/jianyu");
	who->save();
	tell_object(who,"有人举报你有"+crime+"的罪行！\n");
	
	CHANNEL_D->do_channel(me, "rumor",
		sprintf("%s因为"+crime+"被关进监狱啦！\n", who->name(), crime));

	room->delete("is_busy");
	return 1;
}

