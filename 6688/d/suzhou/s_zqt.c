// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"前庭"NOR);
	set("long", @LONG
	这里空荡荡的，只有几株树，几棵草，连水池都没有一个，一个家丁
懒洋洋地打扫着院子。看来甑家也已经不如外表看来那样有实力了。	
LONG
);
	set("exits",([
	"north" : __DIR__"s_zm",
	"south" : __DIR__"s_zzt",
	"west" : __DIR__"s_zcf",
	]));

	set("objects",([
	__DIR__"npc/jiading" : 1,
	]));

	setup();
	replace_program(ROOM);
}
