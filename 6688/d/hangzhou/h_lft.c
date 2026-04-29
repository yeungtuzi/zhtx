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
        set("short", YEL"来凤亭"NOR);
	set("long", @LONG
	亭子滂水而建,部分甚至已经伸出水面.亭子顶端与众不同,只见
亮丽色大理石质地的顶缀在夕阳晚霞照耀下,水光影映中,如宝石流动.当
年庄子过此,感怀与心,于是脱口而出"宝石流霞",从此成为西湖一景.西北
方向通往黄龙洞。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_road1", 
	"west"  : __DIR__"h_road2",
	"northwest" : __DIR__"h_hld",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : 2,
	]));

        setup();
}

