// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"书店");
	set("long", @LONG
	一家书店，专门卖书。
LONG
);

	set("exits",([
	"north" : __DIR__"s_slx5",
	]));
	
	set("objects",([
	__DIR__"npc/s_czj" : 1,
	]));

	setup();
	replace_program(ROOM);
}
