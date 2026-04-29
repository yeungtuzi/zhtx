//by tlang

#include <ansi.h>
inherit ROOM; 

void create()
{
	set("short", HIC"枫桥"NOR);
	set("long", @LONG
	桥身是有大块的石头砌成的，很结实，也很高大。桥离水面极高，即使
是最大的船也能通过。不远处泊桌一艘小船，梢公不知道哪儿去了，只有一个书生
模样的人站在船头，口中念念有词。	  
LONG
	);
	set("outdoors","suzhou"); 
	set("exits", ([
		"enter" : __DIR__"s_boat",
		"north" : __DIR__"szroad11",
		"south" : "/d/suzhou/ngate",
]));             
	setup();
}    











