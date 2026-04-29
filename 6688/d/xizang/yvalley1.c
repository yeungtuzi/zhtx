// /d/xizang/yvalley1.c

inherit ROOM;

void create()
{
        set("short", "峡谷");
        set("long", @LONG
这里是雅鲁藏布江北岸的峡谷.
LONG
        );
        set("exits", ([
        "east" : __DIR__"yvalley",
        "west" : __DIR__"yvalley2",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
