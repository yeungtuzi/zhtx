//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "碎石路");
	set("long", @LONG
	一条小小的由石子铺成的路，即使下雨也能轻快地在上面走，正适合
你目前轻松的心情。往北向上是岳坟，往南是位于苏堤东北方的曲院风荷。
LONG
        );
        set("exits", ([
	"northup"  : __DIR__"h_yfen", 
	"south" : __DIR__"h_qyuan2",
	 ]) );
	
        setup();
}

