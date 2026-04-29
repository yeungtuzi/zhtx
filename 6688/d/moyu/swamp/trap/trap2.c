// trap1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/doom.c";

void create()
{
	set("short", "黑沼绝地");
	set("long", BLK@LONG
落叶败草，堆积腐烂，都化成了软泥，数百年下来，这儿软泥高积。
寂静，毫无生气的绝对的寂静。时间，空间仿佛已经不再存在。
LONG NOR);
	set("exits", ([ /* sizeof() == 2 */
	  "south": __DIR__"trap1",
	  "north": __DIR__"trap3",
	  "northwest": __DIR__"trap5",
	]));
	setup();
}