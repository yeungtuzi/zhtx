//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"舍利塔"NOR);
	set("long", @LONG
	 相传神僧觉远舍身救民，投身火中，身体焚三日三夜始灭，众僧
收拾他的遗骸时，得舍利子九颗，少林保管了六颗，其它三颗散落四方。据
说寒山寺的前辈神僧见空得其一，于是造此塔以供之。
LONG
);
	set("exits", ([
		"west" : __DIR__"s_hssd",
]));                            
	setup();
}





