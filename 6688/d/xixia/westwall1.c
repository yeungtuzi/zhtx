// Room: /d/xixia/southwall1.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "西城墙");
	set("long", @LONG
这段城墙下面正对着城门，较一般的城墙要宽。城墙的中间
矗立着一座高大的城楼，建筑考究，灿然生色。这里戒备森严，
士兵们不时探出头去，留意着城门下发生的一切。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
	  "north" : __DIR__"westwall3",
	  "northdown" : __DIR__"westgate",
	  "southdown" : __DIR__"westgate",
	  "south" : __DIR__"westwall2",
	  "enter" : __DIR__"westtower",
]));
	set("no_clean_up", 0);
	set("objects", ([
			__DIR__"npc/general": 1,
			__DIR__"npc/guard": 2,
		]));
	set("outdoors", "xixia");

	setup();
}

void reset()
{
	delete_temp("alert");
	::reset();
}

//0表示在河里, 1表示在墙中间, 2表示在墙上面
void alert(int where, object who)
{
        object wall, *ob, river;
        int i;

	if( !objectp(river = find_object(__DIR__"xhch")))
                if( !objectp(river = new(__DIR__"xhch")))
			return;

	wall = this_object();

	if( !query_temp("alert") ) {
		set_temp("alert", 1);
		message_vision(HIY"城墙上一阵骚动！\n"NOR, who); 
        	for (i = 0; i < 8; i++) {
			message_vision("城门守卫急急忙忙地赶了过来！\n", who);
                	new(__DIR__"npc/guard")->move(wall);
		}
	}

        if (where == 0) {
                message_vision(CYN"河里好象有人！\n"NOR, who);
                message_vision(HIY"\n出来！不出来我砸石头了！\n"NOR, who);
                call_out("throw_stone", 1);
                call_out("throw_stone", 3);
                call_out("throw_stone", 7);
                return;
        }

        if (where == 2) {
                message_vision(CYN"不好了！有人从下面爬墙上来了！\n"NOR, who);
                ob = all_inventory(wall);

		for( i = 0; i < sizeof(ob); i++)
                	if (!userp(ob[i]))      ob[i]->kill_ob(who);
                return;
        }

        if (where == 1) {
                message_vision(CYN"不好了！有人在爬墙！\n"NOR, who);
                call_out("throw_stone", 1);
                call_out("throw_stone", 3);
                call_out("throw_stone", 7);

                return;
        }

        return;
}

void throw_stone()
{
	object *ob, river;
	int i;

	if( !objectp(river = find_object(__DIR__"xhch")))
                if( !objectp(river = new(__DIR__"xhch")))
			return;

	ob = all_inventory(river);
	for (i = 0; i < sizeof(ob); i++) {
		if( !living(ob[i]))	continue;
		if( !ob[i]->query_temp("step")) {
			tell_object(ob[i], HIY"轰地一声，一块巨石从上面滚了下来，你赶紧将身子一侧，扑通一声，巨石落在水里，登时水花四溅！\n"NOR);
			continue;
		}
		if( ob[i]->query_temp("step") && random(10) == 0) {
			tell_object(ob[i], HIY"轰地一声，一块巨石从上面滚了下来，还好，没砸中你！\n"NOR);
			continue;
		}

		message_vision(HIR"轰地一声，一块巨石从上面滚了下来，$N避无可避，砸个正着，惨叫一声，掉进了河里！\n"NOR, ob[i]);
		ob[i]->unconcious();
		ob[i]->receive_wound("kee", 50 * (10 - (int)ob[i]->query_temp("step")));
		ob[i]->delete_temp("step");
	}

	return;
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_jump", "jump");
//	add_action("action_gate", "gate");
//	add_action("action_bridge", "bridge");
}

int do_jump(string arg)
{
	string skill, desc;
	object me, river;
	int lvl, coeff;

        if( !objectp(river = find_object(__DIR__"xhch")))
                if( !objectp(river = new(__DIR__"xhch")))
                        return 1;

	me = this_player();

        lvl = me->query_skill("move");
        if (stringp(skill = me->query_skill_mapped("move"))) {
                coeff = SKILL_D(skill)->effective_level();
                if( coeff > 0 )
                lvl = lvl * coeff / 10;
        }
        coeff = me->query_encumbrance() * 100 / me->query_max_encumbrance();
        lvl = lvl * (100 - coeff) / 100;

	if( lvl < 251 || me->query("force") < 200 ) {
		message_vision(HIY"$N纵身一跃，从城墙上跳了下去！\n"NOR, me);
		message_vision(CYN"\n不好了，有人跳墙自杀！\n"NOR, me);
		me->move(river);
		tell_room(river, HIY"只听见扑通，" + me->name() + "从上面跳了下来，水花四溅！\n"NOR, me);
		if (lvl < 120) me->unconcious();
		else	me->receive_damage("kee", 300);
		return 1;
	}

	switch( skill ) {
		case "stormdance":
			desc = "蕙芳下凡"; break;
		case "tiyunzong":
			desc = "大鹏展翅"; break;
		case "tie-steps":
			desc = "鹰飞势"; break;
		case "huashan-shenfa":
			desc = "幻眼云湮"; break;
		case "baguabu":
			desc = "风字决"; break;
		case "xiaoyaoyou":
			desc = "蜻蜓点水"; break;
		case "mo-shan-jue":
			desc = "浮云终日行"; break;
		case "zhutian":
			desc = "鹰爪松"; break;
		case "pyrobat-steps":
			desc = "寒蝠掠江"; break;
		case "xianyun":
			desc = "比翼双飞"; break;
		case "notracesnow":
			desc = "腾云驾雾"; break;
		case "fall-steps":
			desc = "草木黄落兮雁南归"; break;
		case "fx-step":
			desc = "大江东去"; break;
		case "shaolin-shenfa":
			desc = "孤骛落日"; break;
		case "chaos-steps":
			desc = "天玑离枢"; break;
		default:
			desc = "细胸巧翻云";
	}

	if (me->query("gender") == "男性") {
		message_vision(HIG"$N足尖轻点，一式「" + desc +"」，空中几个转折，犹如一只大鹏，飘下城去，轻功之高，实令人叹为观止！\n"NOR, me);
		me->move(__DIR__"westroad1");
		tell_room(environment(me), HIG"恍似天神下凡，只见" + me->name() + "从天而降，身形倒退两步，便此凝立当场，威风凛凛！\n"NOR, me);
	}
	else {
		message_vision(HIG"$N足尖轻点，一式「" + desc +"」，空中几个转折，恍若一只飞燕，飘下城去，轻功之高，实令人叹为观止！\n"NOR, me);
		me->move(__DIR__"westroad1");
		tell_room(environment(me), HIG"恍似仙女下凡，只见" + me->name() + "从天而降，身形连转数圈，姿势之妙，令人目眩神驰！\n"NOR, me);
	}
		
	return 1;	
}


int do_climb(string arg)
{
	object me;

	me = this_player();

	write("你趁守卫不注意，身子一缩开始沿城墙向下爬。\n");

	me->move(__DIR__"xhch", 1);
	me->set_temp("step", 10);
	write("你现在在墙上半部分。\n");

	return 1;
}

int action_gate(string arg)
{
	object gate, bridge;
	object me = this_player();

	if (arg != "open" && arg != "close")
		return notify_fail("你只能开(open)或者关(close)城门。\n");
	
	if (!(gate = find_object(__DIR__"westgate")))
		if (!(gate = new(__DIR__"westgate")))
			return notify_fail("找不到南城门。\n");
	if (!(bridge = find_object(__DIR__"southbridge")))
		if (!(bridge = new(__DIR__"southbridge")))
			return notify_fail("找不到吊桥啦！\n");

	if (arg == "open") {
		if (gate->query("exits/south") && bridge->query("exits/north"))
			return notify_fail("城门不是已经开了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(gate, "只听得轰轰作响，千斤石门缓缓升了起来。。。\n");
			tell_room(bridge, "只听得轰轰作响，千斤石门缓缓升了起来。。。\n");
			gate->set("exits/south", __DIR__"westbridge");
			bridge->set("exits/north", __DIR__"westgate");
			return 1;
		}
	}
	else {
		if (!gate->query("exits/south") && !bridge->query("exits/north"))
			return notify_fail("城门不是已经关了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(gate, "只听得轰轰作响，千斤石门缓缓降了下来。。。\n");
			tell_room(bridge, "只听得轰轰作响，千斤石门缓缓降了下来。。。\n");
			gate->delete("exits/south");
			bridge->delete("exits/north");
			return 1;
		}
	}
	
	return 0;
}

int action_bridge(string arg)
{
	object bridge, road;
	object me = this_player();

	if (arg != "up" && arg != "down")
		return notify_fail("你只能升(up)或者放(down)吊桥。\n");
	
	if (!(bridge = find_object(__DIR__"westbridge")))
		if (!(bridge = new(__DIR__"westbridge")))
			return notify_fail("找不到吊桥啦！\n");
	if (!(road = find_object(__DIR__"westroad1")))
		if (!(road = new(__DIR__"westroad1")))
			return notify_fail("找不到大路啦！\n");

	if (arg == "down") {
		if (bridge->query("exits/south") && road->query("exits/north"))
			return notify_fail("吊桥不是已经放下了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(road, "只听得咔咔作响，吊桥缓缓降了下来。。。\n");
			tell_room(bridge, "只听得咔咔作响，吊桥缓缓降了下来。。。\n");
			bridge->set("exits/south", __DIR__"westroad1");
			road->set("exits/north", __DIR__"southbridge");
			return 1;
		}
	}
	else {
		if (!road->query("exits/north") && !bridge->query("exits/south"))
			return notify_fail("吊桥不是已经升起了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(road, "只听得咔咔作响，吊桥缓缓升了起来。。。\n");
			tell_room(bridge, "只听得咔咔作响，吊桥缓缓升了起来。。。\n");
			road->delete("exits/north");
			bridge->delete("exits/south");
			return 1;
		}
	}
	return 0;
} 
