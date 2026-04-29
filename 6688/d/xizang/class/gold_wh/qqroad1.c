// /d/xizang/class/gold_wh/qqroad1.c

inherit ROOM;

void create()
{
        set("short", "崎岖山路");
        set("long", @LONG
这里是一条荒草迷漫的小路,南边是札什伦布寺的后门,东边是连接昆仑山和
西藏草原的山路.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"qqroad",
		"south" : __DIR__"backdoor",
]));
        set("outdoors", "xizang");

        setup();
	replace_program(ROOM);
}
