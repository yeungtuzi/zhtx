// Room: /u/p/pock/bj/road.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"小路"NOR);
	set("long", @LONG
一条平静的碎石小路在树荫下延伸。向东望去，堆秀山上的小亭在树梢
中露出一角。太阳光直照下来，在小路上留下斑驳的树荫。再往西边走两步
就是御花园了。北边的东铁门显得是那么的寂静，没有丝毫生气。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"duixiu",
		"west" : __DIR__"garden",
]));

	setup();
	replace_program(ROOM);
}
