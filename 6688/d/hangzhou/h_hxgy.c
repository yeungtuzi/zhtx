//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"花港观鱼"NOR);
	set("long", @LONG
	这儿紧靠西湖西南角，是有名的花港，几乎所有杭州卖花的女孩都
集中在这儿。少年游客都喜欢来这儿，因为这儿可以看“花”。这儿还有一
样吸引游人的，大概是花儿的香气吸引，西湖的金鲤常来此处，在粼粼的波
光中，凌空跃龙门，传为天下奇观。
LONG
        );
        set("exits", ([
	"northwest"  : __DIR__"h_xslu3", 
	"southeast" : __DIR__"h_cross2",
	 ]) );
	set("objects",([
	__DIR__"npc/fgirl" : 3,
	]));
	
        setup();
}

