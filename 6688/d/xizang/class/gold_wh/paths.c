// /d/xizang/class/gold_wh/paths.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是殿前广场南边的甬道,全部由小块花岗岩铺成.西边是诵经室,你可以听
到香客弟子们诵经的声音,东边是讲经房.法王不喜讲经,通常都是委托一名弟子在
那里代为宣讲.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"lecture",
		 "west" : __DIR__"song",
		"north" : __DIR__"cyard",
		"south" : __DIR__"sroad",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
