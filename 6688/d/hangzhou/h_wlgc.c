//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"ren",
	"h_girl",
	"woman",
});

void create()
{
	int i=random(sizeof(npcs));
        set("short", "武林广场");
	set("long", @LONG
	这是杭州交通要道武林广场,东边是一家医院,东南方向是一个
华丽的亭子,连通到一条繁华的大街,南边是一家大酒楼的后门,西边的
武林门十分热闹,原来那儿通向著名的西湖.
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_dslu3", 
        "south"  : __DIR__"yamen", 
	"southeast"  : __DIR__"chting",
	"east" : __DIR__"h_yyuan",
	"west" : __DIR__"h_wlmen",
	 ]) );

	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1,
		__DIR__"npc/softer" : 1,
        ]) );
 
        setup();
}

