// Room: /d/qingcheng/qchyidao.c

inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"northwest"})
#define MENPAI "青城派"

void create()
{
	set("short", "驿道");
	set("long", @LONG
滚滚黄尘迎面扑来，可见这里来往的人非常多。LONG
LONG
	);
	set("shout", "驿道");
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : "/d/chengdu/beimen",
		"northwest" : __DIR__"dujianyan",
]));

	setup();
//	replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"
