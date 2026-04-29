
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"听雨居"NOR);
	set("long", @LONG
	这是成都市内最有名气的一家客栈。 当年徐子陵入川之时，曾与仙子师妃暄在
此相聚,子陵超然仙去之后，这里也成了来蓉城不可不住的名迹。没有人知道店主人到底
是谁，这也许是成都城内最大的秘密。
LONG
	);

	set("no_fight", 1);
	set("no_cast",1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

//	set("item_desc", ([
//		"paizi" : "楼上雅房，每夜五十两白银。\n",
//	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie1",
//		"up" : __DIR__"kedian2",
	]));

	setup();


}

