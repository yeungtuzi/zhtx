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
	set("short", "广场");
	set("long", @LONG
	 进了庙门，有三道平行的青石台阶引正前方的一个大广场。台阶上
刻的是诸天众佛，五百罗汉以及三千伽蓝的坐像。上了平台，正中方也有个丈
许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕，几位香客正对大殿虔
诚叩拜。
LONG
);
	set("exits", ([
		"northup" : __DIR__"s_hssd",
		"south" : __DIR__"s_hssm",
]));     
	set("objects",([
	"/d/suzhou/"+npcs[i] : 2,
	]));
                       
	setup();
}





