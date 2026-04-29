//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"客房"NOR);
	set("long", @LONG
	 虽然这是客房，但依然保留了九分的方外风格。只见房中一床，一椅，
一桌，一几，床四周雕有飞天，椅子上铺的丝绸上类似袈裟，桌子上有香炉，里
面焚着香，几上的茶杯边放有钵。两位老者正在对弈。
LONG
);
	set("exits", ([
		"west" : __DIR__"s_hssht",
]));  
	set("objects",([
	__DIR__"npc/wang" : 1,
	__DIR__"npc/xinyu" : 1,
	]));
                          
	setup();
}





