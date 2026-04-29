//zhengqitang.c 正气堂
//by emote
inherit ROOM;

void create()
{
	set("short","正气堂");
	set("long",
@LONG
这里就是华山派的正堂了，厅中很宽敞，正中摆着华山派气宗鼻祖岳肃
的画像，下摆一张大供桌，前面有一张大大的交椅，正是华山派掌门之位。
两边各摆着一溜十把交椅，是给来客们坐的地方。正墙上挂着一块匾，上书
三个很大的金字「正气堂」，正是当今华山派掌门--「君子剑」岳不群手书。
    西面有间屋子，是岳不群的书房，东边的屋子，则是岳不群夫妇的卧室。
向后走还有后院。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"shufang",
		"east"  : __DIR__"woshi",
		"south" : __DIR__"hshouyuan",
		"north" : __DIR__"yuanzi",
		
]));
        set("objects", ([
//                 __DIR__"npc/buqun":1,
		"/class/huashan/yue":1,
				 
]));



	setup();
	replace_program(ROOM);
}

