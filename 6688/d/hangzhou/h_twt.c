//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "天外天酒楼");
	set("long", @LONG
	这是一家规模挺大的酒楼，从门前的牌子上可以知道，这是林家在
杭州的连锁酒楼。这里客人挺多的，在这山上，要找到一家酒楼确实也不容
易。所以你到了，小二也没有马上出来，因为太忙了。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_lylu2", 
	"up" : __DIR__"h_twt2",
	 ]) );	
	set("objects",([
	__DIR__"npc/ren" : 1,
	__DIR__"npc/ren2" : 1,
	]));
	
	setup();
}


	

