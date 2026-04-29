//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"blader",
	"sworder",
});

void create()
{
	int i=random(sizeof(npcs));
        set("short", YEL"桃源岭"NOR);
	set("long", @LONG
	你气喘吁吁地爬上山岭,眼界顿时大开.孔子云:登东山而小鲁,
登泰山而小天下.其实不管是什么山,只要是自己花过力气后登上的,都
有一种想飞的感觉,好象自己站在世界之颠.现在你就感觉轻飘飘的,十
分惬意.不远处几个少年正迎风长立,高谈阔论.	
LONG
        );
        set("exits", ([
	"eastdown"  : __DIR__"h_tyl", 
	"north"  : __DIR__"h_tyl3",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));
	
	setup();
}

