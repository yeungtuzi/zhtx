// Room: /open/hihi/menfang1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"后门"NOR);
	set("long", @LONG
这里是林家后门了，后门关的死死的，可以看出这里平时没有什么人在走动。
一般来说，到镖局的人大多都去镖局前半部分办事的。走后门的人更没有了。所
以后门等同于封死了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	  "east" : __DIR__"houyuan",
		]));

	setup();
	replace_program(ROOM);
}
