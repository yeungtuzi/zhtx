//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "河坊街");
	set("long", @LONG
	河坊街是杭州城东南部的一条较繁华的街道，往北是庆春路，往西是
整条大街，往西南就是复兴街。
LONG
        );
        set("exits", ([
	"southwest"  : __DIR__"h_fxj4", 
	"west" : __DIR__"h_nslu",
	"north" : __DIR__"h_qclu", 
	 ]) );
	
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(dir=="west")
	{
		if(random(4)<3)
			return notify_fail("你走在河坊大街上，街上的小贩不停地向你吆喝。\n");
		return 1;
	}
	return 1;
}
*/
