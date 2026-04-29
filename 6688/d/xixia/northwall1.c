// Room: /d/xixia/northwall1.c

inherit ROOM;

void create()
{
	set("short", "北城墙");
	set("long", @LONG
这段城墙下面正对着城门，较一般的城墙要宽。城墙的中间
矗立着一座高大的城楼，建筑考究，灿然生色。这里戒备森严，
士兵们不时探出头去，留意着城门下发生的一切。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "westdown" : __DIR__"northgate",
  "east" : __DIR__"northwall3",
  "west" : __DIR__"northwall2",
  "eastdown" : __DIR__"northgate",
  "enter" : __DIR__"northtower",
]));
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/general": 1,
		__DIR__"npc/guard": 2,
	]));
	set("outdoors", "xixia");

	setup();
}

/*void init()
{
	add_action("action_gate", "gate");
	add_action("action_bridge", "bridge");
}*/

int action_gate(string arg)
{
	object gate, bridge;
	object me = this_player();

	if (arg != "open" && arg != "close")
		return notify_fail("你只能开(open)或者关(close)城门。\n");
	
	if (!(gate = find_object(__DIR__"northgate")))
		if (!(gate = new(__DIR__"northgate")))
			return notify_fail("找不到南城门。\n");
	if (!(bridge = find_object(__DIR__"northbridge")))
		if (!(bridge = new(__DIR__"northbridge")))
			return notify_fail("找不到吊桥啦！\n");

	if (arg == "open") {
		if (gate->query("exits/north") && bridge->query("exits/south"))
			return notify_fail("城门不是已经开了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(gate, "只听得轰轰作响，千斤石门缓缓升了起来。。。\n");
			tell_room(bridge, "只听得轰轰作响，千斤石门缓缓升了起来。。。\n");
			gate->set("exits/north", __DIR__"northbridge");
			bridge->set("exits/south", __DIR__"northgate");
			return 1;
		}
	}
	else {
		if (!gate->query("exits/north") && !bridge->query("exits/south"))
			return notify_fail("城门不是已经关了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(gate, "只听得轰轰作响，千斤石门缓缓降了下来。。。\n");
			tell_room(bridge, "只听得轰轰作响，千斤石门缓缓降了下来。。。\n");
			gate->delete("exits/north");
			bridge->delete("exits/south");
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
	
	if (!(bridge = find_object(__DIR__"northbridge")))
		if (!(bridge = new(__DIR__"northbridge")))
			return notify_fail("找不到吊桥啦！\n");
	if (!(road = find_object(__DIR__"northroad1")))
		if (!(road = new(__DIR__"northroad1")))
			return notify_fail("找不到大路啦！\n");

	if (arg == "down") {
		if (bridge->query("exits/north") && road->query("exits/south"))
			return notify_fail("吊桥不是已经放下了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(road, "只听得咔咔作响，吊桥缓缓降了下来。。。\n");
			tell_room(bridge, "只听得咔咔作响，吊桥缓缓降了下来。。。\n");
			bridge->set("exits/north", __DIR__"southroad1");
			road->set("exits/south", __DIR__"northbridge");
			return 1;
		}
	}
	else {
		if (!road->query("exits/south") && !bridge->query("exits/north"))
			return notify_fail("吊桥不是已经升起了吗？\n");
		else {
			message_vision("$N双手紧握摇轮，用力摇了起来。。。\n", me);
			tell_room(road, "只听得咔咔作响，吊桥缓缓升了起来。。。\n");
			tell_room(bridge, "只听得咔咔作响，吊桥缓缓升了起来。。。\n");
			road->delete("exits/south");
			bridge->delete("exits/north");
			return 1;
		}
	}
	return 0;
} 
