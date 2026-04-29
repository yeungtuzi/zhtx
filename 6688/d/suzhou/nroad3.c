// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;
#include "/d/suzhou/suzhou.h"

void create()
{
	int i=random(sizeof(npcs));
	set("short", HIC"北大街"NOR);
	set("long", @LONG
	     这是一条宽阔的青石街道，向南北两头延伸。南边显得很繁忙。 
西边是一家普通的居民，一家人正在院子里晒太阳。西边有条昏暗的小巷子，
东边一条相当繁荣的街道，北边就是城门了，可通向著名的的钟山。路上是兴
高采烈的游人。
LONG
);
	set("exits",([
	"east" : __DIR__"s_slx",
	"north" : __DIR__"ngate",
	"south" : __DIR__"nroad2",
	"west" : __DIR__"xx2",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
