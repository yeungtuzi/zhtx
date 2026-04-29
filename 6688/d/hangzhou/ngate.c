//ngate.c
//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_gaoshi(object me);

void create()
{
        set("short", "北门");
	set("long", @LONG
	你来到素来与苏州以风景秀丽齐名的杭州城,只见不少游人,过客来来
往往,显的十分热闹.由于这是旅游圣地,所以有不少官兵把守在城门口,更有一
些捕快或者身着皂衣,或者微服,密切注视着来进出的人们.城门上贴有告示(gaoshi).
LONG
        );
        set("exits", ([
	"north"  : "/d/quanzhou/qzroad3", 
	"south"  : __DIR__"h_dslu",
	 ]) );
        set("item_desc", ([
                "gaoshi": (: look_gaoshi :),
        ]) );
	set("objects", ([
		__DIR__"npc/bing" : 2,
        ]) );
 
        setup();
}

string look_gaoshi(object me)
{
        return "近来小霖出任杭州地方官,为了维护风景地区气氛,严禁在城中杀人.\n\n\t\t杭州衙门\n\n\t\t..pp..\n";
}

