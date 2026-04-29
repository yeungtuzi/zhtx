#include <ansi.h>
inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", "三清宫卧房");
	set("long", @LONG
这里是三清宫弟子的卧室。很大的房间里摆着十几张床榻。
几个道士正在休息。右面的墙上挂着几把练功用的木剑。
房间里好象点了檀香，熏得你昏昏欲睡。
LONG
	);
        set("sleep_room",1);
        set("family","茅山派");
        set("no_faint",1);

	set("exits", ([ /* sizeof() == 1 */
  		"southeast" : __DIR__"da_yuan",
]));
        set("objects", ([ /* sizeof() == 2 */
]));
	setup();
}
