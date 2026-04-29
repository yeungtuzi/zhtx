// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;
#include "/d/suzhou/suzhou.h"

void create()
{
	int i=random(sizeof(npcs));
	set("short", MAG"烟花街"NOR);
	set("long", @LONG
	     这是苏州城中最繁荣风流的地方，向东边延伸。南边不时传
来女子甜的让人发麻的调笑声，好象是家妓院。 北边是一家赌馆，里面传
来人们的吆喝声，吵得人头都大了。东边也很热闹，不知道有些什么稀奇
事。西边是一条不怎么惹人注目的小巷子。
LONG
);
	set("exits",([
	"north" : __DIR__"s_dg",
	"east" : __DIR__"s_yhx2",
	"west" : __DIR__"xxiang6",
	"south" : __DIR__"s_lxy",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
