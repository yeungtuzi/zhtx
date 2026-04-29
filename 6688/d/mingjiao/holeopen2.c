// 从这里也通向光明顶的密道。

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "洞穴口");
        set("long", @LONG
光线透过洞口照了进来，然而你目力能及的只有洞口四周，方圆一两
丈内的景物。其余的一切皆笼罩在一片无边的黑暗之中。
LONG
        );
        set("exits", ([ 
		"enter" : __DIR__"yangju",
		"out" : __DIR__"whiterock",
	]));
	set("outdoors","mingjiao");
        setup();
}

