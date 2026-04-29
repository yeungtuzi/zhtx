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
        set("short", "黄龙洞");
	set("long", @LONG
	初次来杭州的人大都以为黄龙洞与金华双龙洞一样，都是一个十分
曲折深邃的洞。其实黄龙洞并不是山洞，而是一座幽静的公园。几经历史变
迁，由佛寺变为道观，又由道观辟为仿古园，如今已经建成以“缘”为主题
的圆缘民俗园。
LONG
        );
        set("exits", ([
	"east" : __DIR__"h_hld3",
	"south"  : __DIR__"h_hld",
	 ]) );

	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1,
        ]) );
 
        setup();
}

	