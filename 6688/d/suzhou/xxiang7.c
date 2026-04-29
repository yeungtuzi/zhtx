// Room: /d/suzhou/xxiang5.c
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
	这是一家专门卖女人首饰的店子，老板不在，只有一位风骚的老板娘
在这儿招呼客人，经常玩泥巴的人都知道，她看上去很眼熟。一些女孩子正在
这儿为自己挑选首饰，一些男人也在为自己的女人挑选首饰。还有一些小混混
正打算浑水摸鱼。
LONG
	);

	set("exits", ([
		"south" :__DIR__"xxiang5",
        ]));

	set("objects", ([
		__DIR__"npc/yfeng" : 1,
		__DIR__"npc/"+npcs[i] : 1,
	]));

	setup();
}

