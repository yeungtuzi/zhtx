// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"后庭"NOR);
	set("long", @LONG
	这里空荡荡的，只有几株树，几棵草，连水池都没有一个。两边的侧
房都关着，也不知道有人住没有。南边的后房里好象有人声传来。
LONG
);
	set("exits",([
	"north" : __DIR__"s_zzt",
	"south" : __DIR__"s_zhf",
	]));

/*	set("objects",([
	__DIR__"npc/jiading" : 1,
	]));
*/
	setup();
	replace_program(ROOM);
}
