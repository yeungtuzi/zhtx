//TORJQ1.C

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这里是通往厚土旗的大道。厚土旗最擅长的是机关建筑学，战阵
之中常常奇兵突出，出奇不意地给敌人以打击，因而深得教主的
器重。
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"center",
		"southeast" :__DIR__"tohtq2",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}