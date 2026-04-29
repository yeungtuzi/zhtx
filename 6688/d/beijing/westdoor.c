// Room: /u/p/pock/bj/westdoor.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"西铁门"NOR);
	set("long", @LONG
这里本来没有必要建造一道门户的。但由于北边就是皇宫的后门神武门
了。为了避免冬天北风穿过神武门直吹御花园，便在神武门南边建造了一道
大屏风。并在屏风两边各建一道铁门，跟宫中相连。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"shngong",
		"east" : __DIR__"pingfeng",
		]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
