// Room: /city/dongmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
	这是东城门，城门正上方刻着“东门”两个楷书大字，官兵们警惕地注
视着过往行人，你最好小心为妙。一条笔直的青石板大道向东西两边延伸。东边
是郊外，隐约可见一片烟雨朦胧，阵阵清香随微风扑面而来。西边是城里。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongjiao1",
		"west" : __DIR__"dongdajie2",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
}
