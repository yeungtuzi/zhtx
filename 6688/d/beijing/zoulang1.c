#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"走廊"NOR);
	set("long", @LONG
这是一条走廊。房顶一侧支在西面的高墙上，另一侧则与东边的太和殿的
屋顶相连。彩梁画栋，连顶棚也用彩漆绘满了各种飞天的图形，每幅精美的雕
画似乎都在诉说一个娓娓动人的故事。往西通往后院，北边是一间房舍，南边
是皇宫的一个小侧门，供宫中太监出入办事之用。
LONG
	);

	set("exits", ([
		"west" : __DIR__"houyuan",
		"east" : __DIR__"qihedian",
	        "north" : __DIR__"fang1",
		"south" : __DIR__"cemen",
	]));

	setup();
}


