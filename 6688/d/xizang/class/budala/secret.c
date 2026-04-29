// /d/xizang/class/budala/secret.c

inherit ROOM;

void create()
{
        set("short", "密道");
	set("long", @LONG
这里是一条阴暗潮湿的密道,充满了难闻的腐烂气味.密道似乎四通八达,但是
因为实在太黑,你无法辨别方向,暗想只能乱闯一气了.
LONG
        );
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
	       "north" : __FILE__,
	       "south" : __FILE__,
		  "up" : __FILE__,
		"down" : __FILE__,
]));
	set("trigger_try", 0);
	setup();
}



int valid_leave(object me, string dir)
{
	if(!userp(me)) {
		me->move(__DIR__"goldball");
		return 1;
	}
	switch(dir) {
		case "north": add("trigger_try", random(10)); break;
		case "east": add("trigger_try", (-1) * random(10)); break;
		case "south": add("trigger_try", (-1) * random(10)); break;
		case "west": add("trigger_try", random(10)); break;
		case "up": add("trigger_try", random(10)); break;
		case "down" : add("trigger_try", (-1) * random(10)); break;
		default: add("trigger_try", 0);
	}
	if (query("trigger_try") >= 130)
		{
	message_vision("$N似乎看到一线亮光,于是小心翼翼地往那里爬去.\n",me);
		me->move(__DIR__"goldball");
		return notify_fail("");
	}
	if (query("trigger_try") <= -130)
		{
	message_vision("$N觉得脚下一空,顺着暗道一直跌落到底.\n",me);
		me->add("kee", -50);
		me->move(__DIR__"trash");
		return notify_fail("");
	}
	message_vision("$N在密道里辛苦地到处爬着.\n",me);
	me->add("kee", -5);
	return 1;
}
