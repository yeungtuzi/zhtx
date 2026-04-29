// This is a room made by roommaker.
//by tlang for wisdomer.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "秘洞");
	set("long", "这是一间什麽也没有的空房间。\n");
	set("exits",([
	"east" : __DIR__"chting",
	]));

	setup();
	replace_program(ROOM);
}
