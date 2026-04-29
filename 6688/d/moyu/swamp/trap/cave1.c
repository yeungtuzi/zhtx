// trap1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/doom.c";

void create()
{
	set("short", "山洞");
	set("long", BLK@LONG
巨大洞穴之内，晃眼间微弱的光浮动，你才能瞧得见四下情状，但见这个洞穴里面比洞口宽大数倍，
尽是黑劫劫的岩壁，显得十分黑暗。洞内空无一物，阴风轻拂，寒意侵人。
LONG NOR);
	set("exits", ([ /* sizeof() == 2 */
	  "east": __DIR__"cave2",
	]));
	setup();
}