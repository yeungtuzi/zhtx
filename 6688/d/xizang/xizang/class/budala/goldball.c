// /d/xizang/class/budala/goldball.c

//#include <room.h>
inherit ROOM;

void create()
{
        set("short", "密室");
	set("long", @LONG
这里是个狭小的石头房间,四外没有窗子,但是有一片温暖柔和的光辉自石桌
上的一颗金色球体(ball)上散发出来.
LONG
        );
	set("item_desc", ([
		"ball" : "这颗金色的球体,似乎微微颤动着,发出嗡嗡的声音.\n",
	]));
        set("exits", ([
		"out" : __DIR__"treasure",
	       "down" : __DIR__"secret",	
	]));
	setup();
//	create_door("south", "石门", "north", DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
	if (dir=="out") {
		message_vision("$N推开一扇石门,悄悄地走了出去.\n", me);
		me->delete_temp("heard");
	}
	return 1;
}

void init()
{
	remove_action("do_hear", "hear");
	add_action("do_hear", "hear");
}

int do_hear(string arg)
{
	object me;
	me = this_player();
	if (!arg || (arg=="") || ((arg!="ball") && (arg!="金球")))
		return notify_fail("你听啊听啊,但是什么也没听到.\n");
	if (random(me->query("int")) < 25){
		tell_object(me,"你听到一个声音说: 看啊,又来了一只呆木瓜!\n");
		return 1;
	}
	else if(!me->query_temp("heard")) {
		tell_object(me,"你听到一个声音说: 你想永生不死吗?\n");
		if(me->query("mud_age") > 100) me->add("mud_age", -10);
		me->set_temp("heard", "ball");
		return 1;
	}
	tell_object(me,"你听到一个声音说: 你好无聊哦,偷听人家聊天.\n");
	return 1;
}
