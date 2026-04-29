// /d/xizang/gongqian.c

inherit ROOM;

void create()
{
        set("short", "宫前街");
        set("long", @LONG
这里是布达拉宫南边的宫前街,北边山上就是布达拉宫,南边是八角街,西
边是一家杂货店.
LONG
        );
        set("exits", ([
  "west" : __DIR__"zshop",
 "north" : __DIR__"uproad",
 "south" : __DIR__"octo14",
]));
        set("objects", ([
                __DIR__"npc/zkid" : 1+random(2),
        ]) );
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
