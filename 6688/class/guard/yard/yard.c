// This is a room made by roommaker.
//modified by tlang for /class/guard/npc/host.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "食堂广场");
	set("long", "你来到平时不开放的食堂广场，只见一位漂亮的姑娘正在向你走来。\n");
	set("no_fight",1);
	set("objects",([
	"/class/guard/npc/host" : 1,
	]));

	setup();
	replace_program(ROOM);
}
