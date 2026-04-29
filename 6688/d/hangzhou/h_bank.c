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
        set("short", HIM"苏堤"NOR);
	set("long", @LONG
	游西湖，最好是携至亲至爱的人骑马满步苏堤，看柳絮飞，看鱼波
兴，看浅草没马蹄，说杭州的美，说西湖的美，说自己身边人儿的美。让你
看的眼睛都迷离了，说得心都化成蜂蜜了。堤上游人甚多。
	
LONG
        );
        set("exits", ([
	"south" : __DIR__"h_bank2",
	"northwest" : __DIR__"h_yfen",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : 2,
	__DIR__"npc/youngman" : 1,
	]));
	setup();
}



