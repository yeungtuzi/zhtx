//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "玉皇山脚");
	set("long", @LONG
	从这儿往北爬上去，就是玉皇山巅了。远远的只见香火环绕山顶，
衬着天上的流云，让人只想尽快上去一睹为快。你不由得加快了脚步。
LONG
        );
        set("exits", ([
	"northup"  : __DIR__"h_yhfy", 
	"southdown" : __DIR__"h_yhlu",
	 ]) );
	
        setup();
}

int valid_leave(object ob,string dir)
{
//	if(random(4)<2)
//			return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	if(dir=="northup")
	{
	tell_object(ob,HIC"你终于爬上了山顶，一道奇观出现在你面前。\n"NOR);
		return 1;
	}
	return 1;
}
