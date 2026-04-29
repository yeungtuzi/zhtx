// Room: /open/hihi/shijie.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"石阶"NOR);
	set("long", @LONG
你来到了一段长长的青石台阶前，在这里向西边看出，隐隐可以看到台阶
上有一个大的广场之类的大平台，而松风观的顶檐也露了出来，在往西走应该
到松风观了吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "westup" : __DIR__"square",
	  "east" : __DIR__"jianchi",
		]));
	setup();
	replace_program(ROOM);
}
