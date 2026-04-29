
inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"northeast"})
#define MENPAI "明教"

void create()
{
	set("short", "昆仑山");
	set("long", @LONG
这里就是昆仑山脚下，东北边有一个小镇.一些穿着白袍的人经常
在这出入
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rqhhtokl4",
	"south" : "/d/road/rkltotgl0",
        "northeast":"/d/mingjiao/xiaozhen",
]));

	setup();
//	replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"