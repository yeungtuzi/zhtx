// Room: /d/quanzhen/road1.c

inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"south"})
#define MENPAI "全真派"

void create()
{
	set("short", "大路");
	set("long", @LONG
一条驿道静静的向远方延伸，旁边车轮滚滚，不少行人走来走去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"road2.c",
		"north" : "/d/jingcheng/ydmen.c",
]));

	setup();
//	replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"