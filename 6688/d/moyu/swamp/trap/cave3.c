// trap1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/doom.c";

void create()
{
	set("short", "山洞");
	set("long", BLK@LONG
地是坚硬的岩石，眼前是一片看不见的黑，只有穴顶一点茫茫的夜空星芒，看来有几丈高，
这石洞居然非常宽敞，但长满了青苔，湿气很重。洞里刚掉落的泥块、青苔、腐木、野菇
一地都是。
LONG NOR);
	set("exits", ([ /* sizeof() == 2 */
	  "south": __DIR__"cave2",
	  "north": __DIR__"cave4",
	]));
	setup();
}