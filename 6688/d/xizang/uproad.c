// /d/xizang/uproad.c

inherit ROOM;

void create()
{
        set("short", "宫前街上坡");
        set("long", @LONG
这是一条上坡路,北边山上就是布达拉宫辉煌的建筑群.
LONG
        );
        set("exits", ([
 "northup" : __DIR__"class/budala/uproad1",
   "south" : __DIR__"gongqian",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
