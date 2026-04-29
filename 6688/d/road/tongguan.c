
inherit ROOM;

#include <ansi.h>

#define POSITION "tongguan"

void create()
{
	set("short", "潼关");
	set("long", @LONG
这里地势险峻，是古来兵家必争之地。你走在这里，心莫名地忐忑起来。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rtgtoca0",
	"east" : "/d/road/rlytotg3",
]));

	setup();
//	replace_program(ROOM);
}

#include "/d/wizard/qiangjie.h"
