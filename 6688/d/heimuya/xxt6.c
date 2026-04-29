// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","猩猩滩");
	set("long", @LONG
这里就是有名的猩猩滩,江水到此拐了一个弯,水流湍急
江水冲击礁石的声音震耳欲聋.江面上一条船也没有,只
有一只木筏系在江边,上面有个黑衣白裤的梢公.
LONG
	);

	set("exits", ([
                "west" :__DIR__"xxt7",
	]));
         set("objects",([
                __DIR__"npc/shaogong1" : 1,
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
        if( me->query("combat_exp") < 20000 ) 
                notify_fail("你刚想跳入水中，可看着湍急的水流，忍不住又退了回来
。\n");

        message_vision("$N不顾危险跳入水中，向对岸游去…\n", me);
        me->move(__DIR__"river");
        return 1;
}

