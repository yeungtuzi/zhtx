// Room: /d/xixia/westgate.c

inherit ROOM;

void create()
{
	set("short", "西城门");
	set("long", @LONG
半圆拱形的城门高达两丈有余，城门上大书“中兴”两字。整个
城门建造得气势宏伟。门口站着几个守城的士兵，不时拦住进城的人
盘问。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"weststreet1",
  "southup" : __DIR__"westwall1",
  "northup" : __DIR__"westwall1",
  "west" : __DIR__"westbridge",
]));
	set("objects", ([
		__DIR__"npc/guard": 2,
	]));
	set("outdoors", "xixia");

	set("no_clean_up", 0);

	setup();
}

void init()
{
	object room;
	string time;
	int is_night;

	if (!(room = find_object(__DIR__"westroad1")))
		if (!(room = new(__DIR__"westroad1")))
			return;

	time = NATURE_D->game_time();
	is_night = strsrch(time, "亥时") >= 0 || strsrch(time, "子时") >= 0
		|| strsrch(time, "丑时") >= 0 || strsrch(time, "寅时") >= 0;

	if (query("exits/west") && is_night) {
		tell_room(this_object(), "天黑了，士兵们把城门关上，把吊桥拉起！\n");
		tell_room(room, "天黑了，士兵们把城门关上，把吊桥拉起！\n");
		delete("exits/west");
		room->delete("exits/east");
		return;
	}

	if ((!query("exits/west") || !room->query("exits/east")) && !is_night) {
		tell_room(this_object(), "天亮了，士兵们把城门打开，把吊桥放下！\n");
		tell_room(room, "天亮了，士兵们把城门打开，把吊桥放下！\n");
		set("exits/west", __DIR__"westbridge");
		room->set("exits/east", __DIR__"westbridge");
		return;
	}

	return;
}
