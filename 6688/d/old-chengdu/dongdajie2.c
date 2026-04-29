// Room: /city/dongdajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
	你走在东大街上，踩着坚实的青石板地面。东边是东城门，可以听到守
城官兵的吆喝声。北边是一座古旧的道法场，道法场的主持张天师，虽然江湖上
声名不扬，但是有关他和茅山派掌门林忌的传闻却一直不断。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"dongdajie1",
		"north" : __DIR__"daofachang",
		"south" : __DIR__"tjdp",
	]));
        set("objects", ([
		"/class/gaibang/he-bj.c":1,
	]));

	setup();
	replace_program(ROOM);
}

