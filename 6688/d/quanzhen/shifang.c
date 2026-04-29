// Room: /u/hacky/quanzhen/shifang.c
// Made by: hacky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "师房");
	set("long", @LONG
师房是王重阳休息的地方,内有一张宽大的床,你看着看着也想躺上去睡一觉了,
但是这可不是你能睡的地方哦.北边是门屋，南边是寝房。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"menwu.c",
  "south" : __DIR__"qinfang.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  	"/class/quanzhen/wang.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
