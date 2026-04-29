// /d/xizang/s_bank.c

inherit ROOM;

void create()
{
        set("short", "雅鲁藏布江南岸");
        set("long", @LONG
这里是雅鲁藏布江南岸,西边一座巍峨的大山就是喜马拉雅山.
LONG
        );
        set("exits", ([
        "westup" : __DIR__"xmly0",
	 "north" : __DIR__"bridge",
]));
        set("resource/water", 1);
        set("objects", ([
                __DIR__"npc/somebody" : 1,
]) );
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
