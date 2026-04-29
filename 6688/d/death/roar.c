// This is roar's room

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "龙五的房间");
	set("ghostplace",1);
	set("long", @LONG
花开花落，再灿烂的星光也会消失
人的一生和这相比只不过是一刹那间的事
在刹那间，人诞生了
而最后一定都要归于死的永眠
战斗和受伤，笑与流泪，喜悦与悲伤，爱谁？恨谁？
在残酷的生存斗争中你才能感受到什么是真正的生活
LONG
	);
	set("exits",([
		"back" : __DIR__"deathhall",
	]));
	setup();
/*	replace(ROOM);*/
}
