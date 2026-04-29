// /d/xizang/road.c

inherit ROOM;

void create()
{
        set("short", "冰川小路");
        set("long", @LONG
这是一条冰川上的小路,你小心翼翼地踩着冰雪,尽力保持身体的平衡,
以防滑倒.
LONG
        );
        set("exits", ([
   "north" : __DIR__"xueshan3",
   "south" : __DIR__"road1",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
