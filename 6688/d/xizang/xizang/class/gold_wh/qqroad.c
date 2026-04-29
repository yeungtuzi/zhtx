// /d/xizang/class/gold_wh/qqroad.c

inherit ROOM;

void create()
{
        set("short", "崎岖山路");
        set("long", @LONG
这里是一条荒草迷漫的小路,南边是座宏伟庄严的寺院,东边是连接昆仑山和
西藏草原的山路.
LONG
        );
        set("exits", ([
		"east" : __DIR__"uroad3",
		"west" : __DIR__"qqroad1",
]));
        set("outdoors", "xizang");

        setup();
	replace_program(ROOM);
}
