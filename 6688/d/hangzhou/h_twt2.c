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
易。这儿虽然是楼上，但人也很多。小二正忙得团团转。 
LONG
        );
        set("exits", ([
	"down" : __DIR__"h_twt",
	 ]) );	
	set("objects",([
	__DIR__"npc/ren" : 1,
	__DIR__"npc/ren2" : 1,
	"/obj/npc/xiaoer2" : 1,
	]));
	
	setup();
}


	

