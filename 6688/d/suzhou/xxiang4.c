// Room: /d/suzhou/xxiang4.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"ren",
	"picker",
	"girl",
	"ren2",
});

void create()
{
	int i=random(sizeof(npcs));

	set("short", MAG"小巷子"NOR);
	set("long", @LONG
	这是一条繁荣的街道，来来往往的旅客和游人在街上逛着，看有没有
合适的东西可买。偶尔也有一两个神色不定的小子挤在人群中伺机下手。
LONG
	);

	set("exits", ([
		"east" : __DIR__"xxiang5",
		"west" : __DIR__"sroad2",
        ]));

	set("objects", ([
		__DIR__"npc/"+npcs[i] : 2,
	]));

	setup();
}

