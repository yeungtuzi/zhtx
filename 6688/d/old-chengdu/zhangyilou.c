#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "张仪楼");
	set("long", @LONG
	这里就是纪念当年张仪筑城的张仪楼，在楼上可以看到百里外终
年积雪的玉垒山和看到从都江堰流出盘绕城周的内江和外江，景致极美。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"ximen",
	]));
	setup();
	replace_program(ROOM);
}
