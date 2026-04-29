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
        set("short", "钱塘大堤");
	set("long", @LONG
	迎面一排浪头凌空而下，似乎要把你吞噬，一排落下之后，又是一
排跃起，再落下，直落在堤边，撞击声响彻云霄。堤边有不少游人正在观看
这潮起潮落。
LONG
        );
        set("exits", ([
	"westup" :__DIR__"h_hroad",
	"southwest"  : __DIR__"h_wyshan", 
	"east" : __DIR__"h_lht",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : random(2),
	__DIR__"npc/traveler" : random(3),
	]));
		
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(dir=="east" || dir=="southwest")
	{
		if(random(4)<2)
			return notify_fail("你往前走着，两边的景色没有什么变化。\n");
		return 1;
	}
	return 1;
}*/