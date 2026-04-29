// /d/xizang/yvalley3.c

inherit ROOM;

void create()
{
        set("short", "峡谷");
        set("long", @LONG
这里是雅鲁藏布江北岸的峡谷.岸边水草丰美,繁花盛开.
LONG
        );
        set("exits", ([
         "eastdown" : __DIR__"yvalley2",
	"northwest" : __DIR__"yvalley4",
]));
	set("outdoors", "xizang");
	set("objects", ([
//                __DIR__"npc/obj/flower" : random(5),
	]));
        setup();
        replace_program(ROOM);
}
