// by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"宝珠山庄大门"NOR);
	set("long", "这儿繁花似锦，草木茂盛，在绿荫丛中，你忽然发现一道门，\n"
"门里面有一条小道，直通向深处。门口藤椅上有个老人在乘凉。\n");
	set("exits", ([
	"enter" : __DIR__"huay",
	"south" : __DIR__"xhroad",
	]));
	set("objects",([
	__DIR__"npc/zhuba" : 1,
	]));
	
	setup();
}
