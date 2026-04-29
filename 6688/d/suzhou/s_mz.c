// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"民宅");
	set("long", @LONG
	一个普通的院子，四周的房门都关着，只有一个中年人在院子中晒着太
阳，看来这家人的日子过的也还不错。
LONG
);

	set("exits",([
	"south" : __DIR__"s_slx",
	]));
	
	set("objects",([
	__DIR__"npc/s_jm" : 1,
	]));

	setup();
	replace_program(ROOM);
}
