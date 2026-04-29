// Room: /city/nanmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long", @LONG
	这是南城门，城墙被当成了广告牌，贴满了花花绿绿各行各业的广告,
官兵们被近处的欢声笑语所吸引，似乎不是很认真在执勤。西南方向是景色清
幽秀美的峨嵋山，不过一般武林人物还是不要随便上山的好。往东南一直走就
到了长江的北岸了。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"southeast" : "/d/road/rcdtodk0",
		"southwest" : "/d/road/rcdtoems0",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
                "/obj/npc/wujiang10" : 1,
                "/obj/npc/bing" : 2,
        ]));

	setup();
}

