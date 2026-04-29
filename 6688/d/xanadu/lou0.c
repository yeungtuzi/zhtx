// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short",CYN"接 天 楼"NOR);
	set("long", @TEXT
	前方是一座高若叁十来丈，座落在树木苍苍的小平顶山上九层的高楼，其台基
边缘有雕刻精细的荷叶净瓶石栏杆，周围出廊，与附近的山庄楼台相连起来，俨然一体。
这些楼阁亭台规模弘整、布局相连，形成了一个庞大的建筑组。人处其内，有种迷失了个
人的渺小感觉．
TEXT
	);

	set("exits", ([ /* sizeof() == 2 */
	  "east" : __DIR__"dynamic/jiuqu9",
	  "enter": __DIR__"lou1",
	]));

	set("objects", ([
			__DIR__"npc/zhanyu" : 1,
		])
	);

	set("blocks/enter","zhan yu");

	setup();
}                               

