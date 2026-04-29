// Room: /d/xixia/yneitang.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "内堂");
	set("long", @LONG
迎面立着一扇屏风，屏风山画的是宫笔山水画，绕过屏风就是
皇太后寝居之所，室内烛台夺目，淡香扑鼻，让人精神恍惚。一个
中年贵妇盘膝坐在罗帐内，想必就是太后，几个宫女一旁侍候着。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neishufang",
  "north" : __DIR__"yneitang2",
]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/qiushui": 1,
		__DIR__"npc/pmaid": 2,
		]));

	create_door("north", "小帘门", "south", DOOR_CLOSED);
	create_door("south", "小帘门", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && me->query("gender") != "女性")
		return notify_fail("那是人家公主的闺房，你又不是驸马，怎么可以随便进去呢？\n");

	return ::valid_leave(me, dir);
}
