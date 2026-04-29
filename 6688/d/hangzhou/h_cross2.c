//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"ren",
	"ren2",
	"ren3",
	"h_girl",
	"h_girl2",
	"h_girl3",
});

void create()
{
	int i=random(sizeof(npcs));
        set("short", GRN"十字路口"NOR);
	set("long", @LONG
	这儿是杭州的交通要道，北边不远处是西湖的苏堤，西边是著名的
虎跑泉，西北边则是花港观鱼，往东是南山大道，往南是又一个十字路口。
LONG
        );
        set("exits", ([
	"west"  : __DIR__"h_hup", 
	"east" : __DIR__"h_nslu4",
	"north" : __DIR__"h_bank2",
	"south" : __DIR__"h_cross",
	"northwest" : __DIR__"h_hxgy",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : random(2),
	__DIR__"npc/traveler" : random(3),
	]));
	
        setup();
}

