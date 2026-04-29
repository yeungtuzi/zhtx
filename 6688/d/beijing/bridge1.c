#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"金水桥"NOR);
        set("long",@TEXT
这就是著名的金水桥，桥下是护城河缓缓的流水。水看上去很清，乃引
自京郊的水库。这里是进皇宫正门的必经之路。北边就是著名的紫禁城了。
不过一般平民是不可能进去的。
TEXT
	);
        set("outdoors", "bj");
        set("exits", ([
                "north" : __DIR__"zijincheng",
                "south" : __DIR__"changjie2",
        ]));
        setup();
}

