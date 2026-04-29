// Room: /open/hihi/shulin.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"树林"NOR);
	set("long", @LONG
你来到了密道的出口，一片小树林之中。这里格外的宁静，甚少有人
在这里走动。树林里的一些昆虫的叫声在宁静的树林里显得非常的诡异，
说不定你能在附近找到一些令人惊喜的东西呢!
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"houmen1",
	]));

	setup();
	replace_program(ROOM);
}
