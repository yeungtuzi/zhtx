// Room: /d/xingxiu/houshan3.c

#include <room.h>
#include <localtime.h>

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里杂草灌木丛生，又潮湿又阴冷，稍不留神就碰到了各种各样的毒虫，看来还是
赶紧离开这个地方的好！南边你看到了一扇窗户。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houshan1",
]));
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/xiezi" : random(2),
		__DIR__"npc/wa" : random(2),
		__DIR__"npc/spider" : random(2),
		__DIR__"npc/wugong" : random(2),
]));
	set("outdoors", "xingxiu");

	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if( !arg || arg=="")
		return notify_fail("你要跳什么？\n");

	if( arg != "窗户" && arg != "window")
		return notify_fail("这里没有"+arg+"。\n");

	if( me->query("mark/ding_chushi") != 2 )
		return notify_fail("你跳来跳去，很爽吗？\n");

	if( localtime(time()*60)[LT_HOUR] > 4 )
		return notify_fail("还是等晚上行事比较好。\n");
	message_vision("$N拉开窗门，轻轻跳了进去。\n", me);
	me->set("mark/ding_chushi", 3);
	me->move(__DIR__"droom");
	return 1;
}
