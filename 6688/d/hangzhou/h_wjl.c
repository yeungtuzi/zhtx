//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"ren",
	"woman",
	"h_girl",
});

void create()
{
	int i=random(sizeof(npcs));
        set("short", "望江楼");
	set("long", @LONG
	楼阁前面的空地上有一些少年在一起互相谈笑,空地中引出一条
石径,至远处渐渐隐入翠绿的柳阴中.拾阶登上楼阁,可以看见西湖北半边
的大致景色,其中断桥残雪,平湖秋月尤其出色.西南方向就是以糖醋鱼驰
名天下的三雅园.
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_wlmen", 
	"west"  : __DIR__"h_road1",
	"north" : __DIR__"xhroad",
	"southwest" : __DIR__"syyuan",
	"south" : __DIR__"h_dqcx",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : 2,
	]));

        setup();
}

