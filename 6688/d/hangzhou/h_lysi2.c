//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "灵隐寺");
	set("long", @LONG
	这儿有许多进香客，虔诚地祈祷。同其它庙宇没有什么不同得是
这儿也有许多佛像。这儿往北是广场，往西是一飞来峰，其它方向的门紧
紧闭着，进去看来是不可能了。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_lysi", 
	"west"  : __DIR__"h_flf",
	 ]) );
	set("objects",([
	__DIR__"npc/xiang-ke" : 2,
	]));
	
	setup();
}


	

