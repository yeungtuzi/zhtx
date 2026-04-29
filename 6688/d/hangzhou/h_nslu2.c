//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "南山大道");
	set("long", @LONG
	西湖东边的一条大道，往北边不远就是庆春大街，往西南边有一家
客栈，路边柳暗花明，莺歌燕舞，有著名的景点柳浪闻莺。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_qclu2", 
	"southwest" : __DIR__"h_kezhan", 
	 ]) );
	
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你走在大路上，两边的景色没有明显的变化。\n");
	return 1;
}*/



