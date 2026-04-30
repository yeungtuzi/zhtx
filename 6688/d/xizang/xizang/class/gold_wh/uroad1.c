// /d/xizang/class/gold_wh/uroad1.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是一条荒草迷漫的小路, 往南延伸到西藏草原，北边据说通往昆仑山.西
边是道并不算很陡峭的山崖(cliff),好象可以爬(climb)上去.
LONG
        );
        set("exits", ([
                "northup" : __DIR__"uroad2",
              "southdown" : "/d/xizang/klroad0"
]));
        set("outdoors", "xizang");

        setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        // 2026-04-30: unused variable commented out
        // object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "cliff" || arg == "up" || arg == "山崖") {
	me = this_player();
	message_vision("$N抓着突出的石角，慢慢的顺着山崖攀爬上去。\n", me);
	me->start_busy(4);
	call_out("fliping",4, me);
	me->stop_busy();
	return 1;
	} else {
		write("你不可以爬"+arg+"\n");
		return 1;
	}
}

int fliping(object me)
{
	me->move(__DIR__"cliff");
	message_vision("$N顺着山崖爬了上来。\n", me);
	return 1;
}
