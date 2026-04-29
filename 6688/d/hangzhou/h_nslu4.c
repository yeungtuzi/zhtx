//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "南山大道");
	set("long", @LONG
	一条紧靠西湖的大道，北边就是碧蓝的湖水，往东可以通向夕照山，
往西是个十字路口。南面远远地可以望见玉皇顶上巍峨的庙宇。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_nslu3", 
	"west" : __DIR__"h_cross2", 
	 ]) );
	
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	return 1;
}*/



