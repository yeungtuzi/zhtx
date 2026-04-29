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
        set("short", "灵隐寺广场");
	set("long", @LONG
	这儿是灵隐寺前的广场，许多人在这儿看云海，也有一些外国人。
其中的一些人还拿着照相机为大家照相。往南边就是寺门，远远忘去，香火
也算不错。
LONG
        );
        set("exits", ([
	"down"  : __DIR__"h_yxt", 
	"south"  : __DIR__"h_lysi2",
	 ]) );
	set("objects",([
	__DIR__"npc/foreiger" : 1,
	__DIR__"npc/"+npcs[i] : 2,
	]));
	
	setup();
}


	

