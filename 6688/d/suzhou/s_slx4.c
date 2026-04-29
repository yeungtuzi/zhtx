// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;
#include "/d/suzhou/suzhou.h"

void create()
{
	int i=random(sizeof(npcs));
	set("short", HIC"十里长街"NOR);
	set("long", @LONG
	     这是一条宽阔的青石街道，向东西两头延伸。北边是一家裁缝店，
南边是一家普通民宅。整个地方显的有些冷寂。
LONG
);
	set("exits",([
	"west" : __DIR__"s_slx3",
	"east" : __DIR__"s_slx5",
	"south" : __DIR__"s_mz2",
	"north" : __DIR__"s_cfd",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
