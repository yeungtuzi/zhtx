// Room: /d/xixia/southgate.c

inherit ROOM;

void create()
{
	set("short", "南城门");
	set("long", @LONG
半圆拱形的城门高达两丈有余，城门上大书“中兴”两字。整个
城门建造得气势宏伟。门口站着几个守城的士兵，不时拦住进城的人
盘问。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"southbridge",
  "eastup" : __DIR__"southwall1",
  "north" : __DIR__"southstreet1",
  "westup" : __DIR__"southwall1",
]));
	set("objects", ([
		__DIR__"npc/guard": 2,
		]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
}

void init()
{
	object road;
	string time;
	int is_night;

	if (!(road = find_object(__DIR__"southroad1")))
		if (!(road = new(__DIR__"southroad1")))
			return;

	time = NATURE_D->game_time();
	is_night = strsrch(time, "亥时") >= 0 || strsrch(time, "子时") >= 0 || strsrch(time, "丑时") >= 0 || strsrch(time, "寅时") >= 0;

	if (query("exits/south") && is_night) {
		tell_room(this_object(), "天黑了，士兵们把城门关上，把吊桥拉起！\n");
		tell_room(road, "天黑了，士兵们把城门关上，把吊桥拉起！\n");
		delete("exits/south");
		road->delete("exits/north");
		return;
	}

	if ((!query("exits/south") || !road->query("exits/north")) && !is_night) {
		tell_room(this_object(), "天亮了，士兵们把城门打开，把吊桥放下！\n");
		tell_room(road, "天亮了，士兵们把城门打开，把吊桥放下！\n");
		set("exits/south", __DIR__"southbridge");
		road->set("exits/north", __DIR__"southbridge");
		return;
	}

	return;
}
