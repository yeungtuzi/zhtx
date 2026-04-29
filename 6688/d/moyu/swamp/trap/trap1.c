// trap1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/doom.c";

void create()
{
	set("short", "黑沼绝地");
	set("long", BLK@LONG
四周弥漫着腐落泥沼的令人窒息气味，到处都是一片黑暗。但是可
怕的不是黑暗，不是寂静，亦不是腐败的气味，而是“绝望”，是
逃不出这幽冥世界的绝望。
LONG NOR);
	
	set("exits", ([ /* sizeof() == 2 */
	  "north": __DIR__"trap2",
	]));
	
	setup();
}