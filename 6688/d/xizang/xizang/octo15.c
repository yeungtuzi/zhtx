// /d/xizang/octo15.c

inherit ROOM;

void create()
{
        set("short", "八角街");
        set("long", @LONG
这里是八角街的东北角,东边有一家商号,人来人往,热闹非凡.西边是
去往宫前街的路口,北边一道石墙挡路.站在这里就可以听到布达拉宫的喇
嘛早晚诵经的声音.
LONG
        );
        set("exits", ([
  "west" : __DIR__"octo14",
  "south" : __DIR__"octo16",
  "east" : __DIR__"shop",
]));
        set("outdoors", "xizang");
        setup();
}
// 这里增加翻墙的功能

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if(!arg || arg =="" ) return 0;
	if(arg != "墙" && arg !="wall") 
		return notify_fail("这里没有"+arg+"可爬\n");
	message_vision("$N看看四下无人注意,手忙脚乱地爬上了墙头.\n",
		this_player());
	call_out("flip", 1, this_player());
	return 1;
}

void flip(object ob)
{
	ob->move(__DIR__"storage");
	message_vision("$N从石墙上翻了进来.\n", ob);
}
