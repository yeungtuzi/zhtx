
inherit ROOM;

void create()
{
	set("short", "东郊");
	set("long", @LONG
	向东渐行渐远，你几乎怀疑自己来到了另外一个世界。穿行于树林花丛
之间，空山寂寂，鸟鸣啾啾,不时有阵阵水声传来，树丛深处隐隐露出草堂一角。
你加快了脚步，想探访一下这人间仙境里面的隐者.
LONG
	);
        set("outdoors", "city");

	set("exits", ([
			"south" : __DIR__"caotang",
			"northwest" : __DIR__"dongjiao1",
//			"northeast" : __DIR__"xiaoxi",
	]));

	setup();
	replace_program(ROOM);
}

