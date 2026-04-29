#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "笼翠庵");
	set("long", @LONG
	这是一座清雅的尼姑庵，庵中陈列朴素，一尘不染。由于不是每
个人都有机会到峨嵋山去进香，这里香火极盛。不过现在庵中只有住持静
清师太在和她的密友妙玉在谈些什么。
LONG
	);
	set("exits", ([
		"north" : __DIR__"dongjiao1",
	]));
	set("no_fight", "1");  
	set("no_cast","1");
	set("no_poison","1");
	set("objects", ([ 
		__DIR__"npc/obj/denotation" : 1,
		__DIR__"npc/miaoyu" : 1,
		__DIR__"npc/jingqing" : 1,		
	]));

	setup();
	replace_program(ROOM);
}
