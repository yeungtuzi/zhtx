// /d/xizang/mountain.c

inherit ROOM;

void create()
{
        set("short", "大山");
        set("long", @LONG
这里是一座白雪覆盖的大山,雅鲁藏布江就是发源于此.
LONG
        );
        set("exits", ([
        "southdown" : __DIR__"yvalley4",
          "northup" : __DIR__"peak",
]));
	set("objects", ([
		__DIR__"npc/wolfx" : 1,
	]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
