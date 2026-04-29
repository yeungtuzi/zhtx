//by tlang
       
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"npc/ren",
	"npc/ren2",
	"hill/npc/xiang-ke",
});

void create()
{
	int i=random(sizeof(npcs));
	set("short", "后庭");
	set("long", @LONG
	 过了大殿，有三道平行的青石台阶引到寺庙后庭。只见满庭木棉树，
高高挺立，上面挂着火红的花儿。进罢香的人们在这儿找到一分轻松。也有远
来的客人就在后庭两边的客房里住了下来。
LONG
);
	set("exits", ([
		"southup" : __DIR__"s_hssd",
		"east" : __DIR__"s_hssf",
		"west" : __DIR__"s_hssf2",
]));   
	set("objects",([
	"/d/suzhou/"+npcs[i] : 2,
	]));
	                         
	setup();
}





