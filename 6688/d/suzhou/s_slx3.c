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
	     这是一条宽阔的青石街道，向东西两头延伸。南边可以看见甑家
高大的围墙，并且可以听见里面抑扬挫的诵书声，大概是甑老先生又在读书。北
边是葫芦庙的围墙，都已经破败不堪了。
LONG
);
	set("exits",([
	"west" : __DIR__"s_slx2",
	"east" : __DIR__"s_slx4",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
