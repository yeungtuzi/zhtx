// /d/xizang/class/gold_wh/pathw.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是殿前广场西边的甬道,全部由小块花岗岩铺成.往西是一条石板路,通往
新筑成的高塔,北边是中央大殿的西厢房,供本寺弟子休息,南边是诵经室,耗憧梢�
听香客弟子们诵经的声音.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"cyard",
		 "west" : __DIR__"wroad",
		"north" : __DIR__"west",
		"south" : __DIR__"song",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
