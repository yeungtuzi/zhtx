// /d/xizang/road1.c

inherit ROOM;

void create()
{
        set("short", "雪山小路");
        set("long", @LONG
这是一条雪山小路,冰雪之下已经露出了一些黑色的泥土,但是路仍然很
滑,你小心翼翼地踩着冰雪,尽力保持身体的平衡,以防滑倒.从这里往南似乎
是一个山谷,但是路不太好走.
LONG
        );
        set("exits", ([
     "north" : __DIR__"road",
 "southdown" : __DIR__"road2",
]));
        setup();
        replace_program(ROOM);
}
