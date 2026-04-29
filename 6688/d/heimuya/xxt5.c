// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","猩猩滩");
	set("long", @LONG
这里就是有名的猩猩滩,山石一片血红,令你不禁有一股说不出的
郁闷感觉,江面上一条船也没有,只有一只木筏系在江边,上面有
个黑衣白裤的梢公.你要么自己游(swim)过去,要么向他打听一下
如何过河.
LONG
	);

	set("exits", ([
                "east" :__DIR__"xxt4",
	]));

	 set("objects",([
                __DIR__"npc/shaogong" : 1,
        ]));

	set("outdoors", "heimuya");
	setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim(string arg)
{
        object me;

	if( arg) return notify_fail("这是岸上，你乱比划什么？\n");
        me = this_player();
	if( me->query("combat_exp") < 10000 ) 
		notify_fail("你刚想跳入水中，可看着湍急的水流，忍不住又退了回来 。\n");
        message_vision("$N不顾危险跳入水中，向对岸游去…\n", me);
        me->move(__DIR__"river");
        return 1;
}

