#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "三清宫储藏室。");
	set("long", @LONG
这里是三清宫的储藏室。一间小小的房间里摆满了香烛
符纸、以及各种兵刃。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"da_dian",
]));
        set("objects", ([ /* sizeof() == 2 */
	__DIR__"obj/sword1":3,
	"/obj/magic/paper_seal":3 ,
]));
	create_door("west", "木门", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
