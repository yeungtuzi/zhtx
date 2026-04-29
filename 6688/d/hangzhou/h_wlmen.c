//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIM"武林门"NOR);
	set("long", @LONG
	这是杭州武林门,名字的来由已经无从查考,但地方实在是出名.
因此竟有不少迁客骚人不远千里赶来,为的只不过是想要在武林门外一舒
胸意.从此处往西可以见到一座秀丽的楼阁,楼阁前有一片空地.
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_wlgc", 
	"west"  : __DIR__"h_wjl",
	 ]) );
	
        setup();
}

