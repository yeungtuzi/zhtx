// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"裁缝店");
	set("long", @LONG
	一家裁缝店，为人做衣服，也卖衣服。
LONG
);

	set("exits",([
	"south" : __DIR__"s_slx4",
	]));
	
	set("objects",([
	__DIR__"npc/tailor" : 1,
	]));

	setup();
	replace_program(ROOM);
}
