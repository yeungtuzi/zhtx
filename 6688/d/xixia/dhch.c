// Room: /d/xixia/nhch.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "护城河");
	set("long", @LONG
处身在护城河下,一边是高不可攀的城墙,一边则是一望无际的草原
和荒漠, 河水在身边缓缓流过, 带来阵阵寒意, 好在自己是习武之
人, 这点寒气也不在乎了. 
LONG);
	set("exits", ([
]));

	set("outdoors", "xixia");

	setup();
}

void init()
{
	add_action("do_look", "look");
	add_action("do_climb", "climb");
	add_action("do_swim", "swim");
	add_action("do_jump", "jump");
}

int do_look(string arg)
{
	if( this_player()->query_temp("step") ) {
		if (arg == "up")
			write("上面是戒备森严的城楼。\n");
		else if (arg == "down")
			write("下面是冰冷的护城河水。\n");
		else if (!arg)
			write("你现在在墙壁上。\n");
		else	write("你现在正在墙壁上，还是专心爬墙吧，不要东张西望了！\n");
		return 1;
	}

	return 0;
}

int do_jump(string arg)
{
	object me, weapon, wall;
	int step;
	string weapon_type;

        if( !objectp(wall = find_object(__DIR__"eastwall1")))
                if( !objectp(wall = new(__DIR__"eastwall1")))
			return 1;
	if (!arg || (arg != "up" && arg != "down"))
		return notify_fail("你是要往上面(up)跳还是要往下面(down)跳？\n");

	me = this_player();
	step = (int)me->query_temp("step");

	if( arg == "down" ) {
		if( !step )
			return notify_fail("你已经在河里了！\n");
		else {
			me->delete_temp("step");	
			message_vision(HIY"$N\"扑通\"一声，跳进了河里。\n"NOR, this_player());
			wall->alert(0, me);
			return 1;
		}
	}

	weapon = me->query_temp("weapon");
	if( objectp(weapon) )	weapon_type = (string)weapon->query("type");
	else	weapon_type = 0;

	if( !step )
		return notify_fail("你处身在水里，无半点凭借之处，怎么施展绝顶轻功？ 不如到岸上去试试吧！\n");
	else if( step < 8 || (step == 8 && (weapon_type != "whip"))) {
		message_vision(HIY"$N借双手攀援之力，向上纵去，可惜在半空中又掉了下来，扑通一声，掉进了河里，摔了个四脚朝天。\n"NOR, me);
		me->receive_damage("kee", 100);
		COMBAT_D->report_status(me, me, 0);
		me->delete_temp("step");	
		wall->alert(0, me);
		return 1;
	} else if( step == 8 ) {
		me->delete_temp("step");	
		message_vision(HIG"$N" + weapon->name() + "一扬，卷住了城墙上的一块巨石，跟着全身借力往上纵跃，宛若鹞子翻身，轻飘飘的降落在城墙上面！\n"NOR, me);
		me->move(wall);
		message_vision(HIG"守卫直看得目瞪口呆，竟不敢报警！\n"NOR, me);
		return 1;
	} else {
		message_vision(HIG"眼看就要爬上城墙了，$N借双手攀援之力，噌地一下向上纵去, 结果稳稳当当地落在了城墙上面。\n"NOR, me);
		wall->alert(0, me);
		return 1;
	}

	return 0;
}

int do_swim(string arg)
{
	object me;

	me = this_player();

	if (me->query_temp("step"))
		return notify_fail("你现在正在墙壁上，先爬下来再说吧！\n");

	if (me->query_skill("swiming"))
		message_vision("$N向着岸边游了过去。\n", me);
	else {
		if( me->query("force") < 100 ) {
			write("你不会游泳，又没了内力运龟息功，会淹死的！\n");
			return 1;
		}
		me->add("force", -100);
		tell_object(me, "你深吸一口气，运起龟息功，朝着对岸走了过去。\n");
		tell_room(this_object(), me->name() + "深深吸了一口气，然后朝着对岸奋不顾身得走了过去，不会游泳？！\n", me);
	}

	me->start_busy(1);
	call_out("arrived", 1, me);

	return 1;
}

void arrived(object me)
{
	me->move(__DIR__"eastroad1");

	message_vision("$N上岸了，深深地透了口气。\n", me);
}

int do_climb(string arg)
{
	string time, skill;
	int lvl, coeff, i, step;
	object me, *ob, wall;

        if( !objectp(wall = find_object(__DIR__"eastwall1")))
                if( !objectp(wall = new(__DIR__"eastwall1")))
			return 1;
	if (!arg || (arg != "up" && arg != "down"))
		return notify_fail("你只能贴着城墙向上(up)或向下(down)爬。\n");

	me = this_player();

	if (me->query("kee") < 30) {
		write("你体力似乎不够，先歇歇吧！\n");
		return 1;
	}

	lvl = me->query_skill("move");
	if (stringp(skill = me->query_skill_mapped("move"))) {
		coeff = SKILL_D(skill)->effective_level();
                if( coeff > 0 )
		lvl = lvl * coeff / 10;
	}
	coeff = me->query_encumbrance() * 100 / me->query_max_encumbrance();
	lvl = lvl * (100 - coeff) / 100;

	if (!me->query_temp("step") && arg == "up") {
		if (wall->query_temp("alert"))
			return notify_fail("城墙上面刚刚发生了骚乱，现下戒备森严，要想爬墙上去是不大可能了。\n");

		time = NATURE_D->game_time();

        	if( !(strsrch(time, "亥时") >= 0 || strsrch(time, "子时") >= 0
	   	   || strsrch(time, "丑时") >= 0 || strsrch(time, "寅时") >= 0))
			return notify_fail("现在又没关城门，犯得着爬墙吗？！\n");

		if (lvl < 60)	return notify_fail("你轻功不够，看来还要多练练！\n");
		if (lvl < 75 && me->query_cor() < 25)
			return notify_fail("你想了想，太危险了，不敢爬。\n");

		message_vision("$N手脚并用，贴着城墙敏捷地向上爬去！\n", me);
		me->start_busy(1);
		me->add("kee", -30);
		me->add_temp("step", 1);
		write("你现在在墙脚下。\n");
		return 1;
	}

	if (!me->query_temp("step") && arg == "down") {
		message_vision("$N在河里爬来爬去，活像个。。。。。。\n", me);
		return 1;
	}

	if (me->query_temp("step")  == 1 && arg == "down") {
		message_vision("$N终于爬下了城墙，长嘘了一口气！\n", me);
		me->start_busy(1);
		me->add("kee", -30);
		me->delete_temp("step");
		return 1;
	}

	if (me->query_temp("step") < 5) {
		me->start_busy(1);
		me->add("kee", -30);
		if (arg == "up") {
			message_vision("$N手脚并用，悄悄地向上面爬去。。。\n", me);
			me->add_temp("step", 1);
			if (me->query_temp("step") != 5)
				write("你现在还在墙的下半部分。\n");
			else	write("你现在到了墙的中部，要小心啦！\n");
		}
		if (arg == "down") {
			message_vision("$N手脚并用，悄悄地向下面爬。。。\n", me);
			me->add_temp("step", -1);
			if (me->query_temp("step") != 5)
				write("你现在还在墙的上半部分。\n");
			else	write("你现在到了墙的中部，可以松口气了！\n");
		}

		return 1;
	}

	if ( me->query_temp("step") == 10 && arg == "up") {
		me->delete_temp("step");
		me->start_busy(1);
		write("你趁守卫转身之际，悄悄地爬进城墙内。\n");
		me->move(wall);
		
		ob = all_inventory(environment(me));
		for (i = 0; i < sizeof(ob); i++) {
			if (ob[i] == me)	continue;
			if (living(ob[i]) && random(me->query("combat_exp") + ob[i]->query("combat_exp")) > me->query("combat_exp")) {
				tell_object(ob[i], HIY"突然城墙下探出一个头来，然后就见" + me->name() + "鬼鬼祟祟地上了城墙。\n"NOR);
				if( !userp(ob[i]) ) {
					wall->alert(2, me);
					return 1;
				}
			}
		}

		return 1;
	}

	if (arg == "up") {
		message_vision("$N手脚并用，悄悄地向上面爬去。。。\n", me);
		me->add_temp("step", 1);
	}
	if (arg == "down") {
		message_vision("$N手脚并用，悄悄地向下面爬。。。\n", me);
		me->add_temp("step", -1);
	}

	me->add("kee", -30);
	i = random(lvl / 10); 
	if (i < 3) {
		message_vision(HIY"城门守卫似乎听到了什么，拿灯笼往城下照！\n"NOR, me);
		tell_room(wall, HIY"城门守卫似乎听到了什么，拿灯笼往城下照！\n"NOR);
		write("你赶忙将身子往墙上紧贴，大气都不敢出一口！\n");
		if (i > 0) {
			write("还好，没发现，不过额头都已经涔涔冷汗了！\n");
			return 1;
		}
		wall->alert(1, me);
	}	

	return 1;
}
