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
	     这是苏州城中最繁荣风流的地方，向东西边延伸。南边不时传来
女子甜的让人发麻的调笑声，好象是家妓院， 南边也一样，西边更吵，东边好
象只有些得意的少年同着年轻的姑娘挑选着东西。
LONG
);
	set("exits",([
	"west" : __DIR__"s_yhx",
	"north" : __DIR__"s_lqy",
	"south" : __DIR__"s_ldy",
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}
