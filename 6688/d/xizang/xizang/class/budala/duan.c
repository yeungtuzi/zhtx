// /d/xizang/class/budala/duan.c

inherit ROOM;

void create()
{
        set("short", "断事司");
        set("long", @LONG
这里是布达拉宫内附设的断事司,负责整个藏边的行政事务,与一般地方的官府
作用相当.断事官端坐大堂正中,两旁有甬道通往东西殿.
LONG
        );
        set("exits", ([
          "northup" : __DIR__"ustair2",
	"southdown" : __DIR__"ustair1",
	     "west" : __DIR__"wpath2",
	     "east" : __DIR__"epath2",
]));
        set("objects", ([
                __DIR__"npc/duanshig" : 1,
                ]));
        setup();
        replace_program(ROOM);
}
