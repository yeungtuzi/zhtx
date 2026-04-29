
inherit ROOM;
#include <ansi.h>
#define BAN_DIR ({"southwest"})
#define MENPAI "峨嵋派"

void create()
{
	set("short", "峨眉山脚下");
	set("long", @LONG
这里是峨眉山的脚下, 西南方向远远的可以看到上山的石阶
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"northeast" : "/d/road/rcdtoems1.c",
	"southwest" : "/d/emei/shijie10.c",
]));

	setup();
//	replace_program(ROOM);
}

#include "/d/wizard/guardshm.h"