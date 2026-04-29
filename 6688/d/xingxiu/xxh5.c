// Room: /d/xingxiu/xxh5.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "星宿海深处");
	set("long", @LONG
这里已经离星宿海的入口很远了。往北你终于看到一个比较宽阔的平地。
走在这种沼泽湖泊地上可真不好受！几个星宿派弟子站在这里似是等待
什么！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"floor",
  "south" : __DIR__"xxh4",
]));
	set("objects", ([
		__DIR__"npc/gushou" : 1,
		__DIR__"npc/boshou" : random(2),
		__DIR__"npc/haoshou" : random(2),
]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiu");

	setup();
}
