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
	set("short", "十字路口");
	set("long", @LONG
	这儿是杭州的一个交通要道，往南过了钱塘江石桥就是杭州南门了，
往北不远就是西湖，西边可以到五云山，东边是一条大街。
LONG
        );
        set("exits", ([
	"west"  : __DIR__"h_lht", 
	"east" : __DIR__"h_fxj",
	"north" : __DIR__"h_cross2",
	"south" : __DIR__"h_brige",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : random(2),
	__DIR__"npc/traveler" : random(3),
	]));
		
        setup();
}

