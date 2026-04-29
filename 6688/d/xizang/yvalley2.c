// /d/xizang/yvalley2.c

inherit ROOM;

void create()
{
        set("short", "峡谷");
        set("long", @LONG
这里是雅鲁藏布江北岸的峡谷.岸边水草丰美,繁花盛开.
LONG
        );
        set("exits", ([
        "east" : __DIR__"yvalley1",
      "westup" : __DIR__"yvalley3",
]));
	set("outdoors", "xizang");
	set("objects", ([
//                __DIR__"npc/obj/flower" : random(5),
	]));
        setup();
        replace_program(ROOM);
}
