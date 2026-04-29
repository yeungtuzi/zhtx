//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "碎石小路");
	set("long", @LONG
	一条碎石子铺成的小路，路上行人不多，而且商人模样的人居多。
也有一些老者，相互提携着，聊着天，快乐地走着。
LONG
        );
        set("exits", ([
	"northeast"  : __DIR__"h_xhx", 
	"southwest" : __DIR__"h_ljlu2",
	 ]) );
	set("objects",([
	__DIR__"npc/oldm" : 1,
	__DIR__"npc/shang" : 2,
	]));
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	return 1;
}*/