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
	     这是一条宽阔的青石街道，向东西两头延伸。北边是一家药铺，
南边是当地的一家书店，只可惜进去借书的人并不多见。东边已经到了长街的
尽头。
LONG
);
	set("exits",([
	"west" : __DIR__"s_slx4",
	"south" : __DIR__"s_sd",
	"north" : __DIR__"s_yp",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
