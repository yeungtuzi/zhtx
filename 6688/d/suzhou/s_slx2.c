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
	     这是一条宽阔的青石街道，向东西两头延伸。南边是一家大宅院，
据说是甑士隐老先生家的。 北边是本地有名的葫芦庙，庙中香火却不旺盛。
LONG
);
	set("exits",([
	"west" : __DIR__"s_slx",
	"east" : __DIR__"s_slx3",
	"north" : __DIR__"s_hlm",
	"south" : __DIR__"s_zm",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
