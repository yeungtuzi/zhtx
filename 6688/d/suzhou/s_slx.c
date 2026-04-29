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
	     这是一条宽阔的青石街道，向东西两头延伸。南边是一家连锁饭店。 
北边是一家普通的民宅，一个居民正在院子里晒太阳。东边有几栋大房宇，看上去
相当气派。西边是北大街。
LONG
);
	set("exits",([
	"west" : __DIR__"nroad3",
	"east" : __DIR__"s_slx2",
	"north" : __DIR__"s_mz",
	"south" : __DIR__"s_fguan",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
