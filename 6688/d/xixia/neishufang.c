// Room: /d/xixia/neishufang.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "青凤阁内书房");
	set("long", @LONG
你的眼前陡然一亮，原来已经置身于一个大厅堂之中，比之外面的
凝香堂犹大了三分，四壁贴满了字画，堂侧放了一张紫杉木大书桌，桌上
放着文房四宝、碑贴古玩之类。更有几座书架，三四张石凳、石几。这里
挤满了来自四方的求婚者。北边你看到了一扇小帘门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yongdao",
  "north" : __DIR__"yneitang",
]));
	set("objects", ([
		__DIR__"npc/qiaofeng": 1,
		__DIR__"npc/xuzhu": 1,
		__DIR__"npc/duanyu": 1,
		__DIR__"npc/tubowangzi": 1,
		__DIR__"npc/murongfu": 1,
		__DIR__"npc/zhudanchen": 1,
		__DIR__"npc/batianshi": 1,
		__DIR__"npc/baobutong": 1,
		__DIR__"npc/fengboe": 1,
		__DIR__"npc/yymaid": 1,
	]));

	create_door("north", "小帘门", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
