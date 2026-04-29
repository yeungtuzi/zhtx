// /d/xizang/class/gold_wh/cliff.c

inherit ROOM;

void create()
{
	set("short", "山崖边");
	set("long", @LONG
这是一道不太高也不太陡峭的山崖,似乎可以从这里跳(jump)下去.山崖下就是
连接西藏草原和昆仑山的山路.西边是札什伦布寺的练武场.
LONG
	);
	set("exits", ([
		"west" : __DIR__"sroad1",
]));
	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me;
	if (! arg || (arg=="")) 
		return notify_fail("你原地跳了几下,当作锻炼身体.\n");
	if ( (arg == "down") || (arg=="cliff") || (arg=="山崖") ) {
		me = this_player();
		message_vision("$N走到山崖边,纵身跳了下去!\n", me);
		me->add("kee", -20);
		if (me->query_skill("dodge", 1) < 50)
			me->improve_skill("dodge", random(me->query("con"))*2);
		me->move(__DIR__"uroad1");
	}
	return notify_fail("你不可以跳"+arg+".\n");
}
